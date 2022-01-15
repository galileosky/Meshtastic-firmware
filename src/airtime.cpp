#include "airtime.h"
#include "NodeDB.h"
#include "configuration.h"


AirTime *airTime;

// Don't read out of this directly. Use the helper functions.


void AirTime::logAirtime(reportTypes reportType, uint32_t airtime_ms)
{

    uint8_t channelUtilPeriod = (getSecondsSinceBoot() / 10) % CHANNEL_UTILIZATION_PERIODS;
    uint8_t channelUtilTXPeriod = (getSecondsSinceBoot() / 10) % CHANNEL_UTILIZATION_PERIODS;

    if (reportType == TX_LOG) {
        DEBUG_MSG("AirTime - Packet transmitted : %ums\n", airtime_ms);
        this->airtimes.periodTX[0] = this->airtimes.periodTX[0] + airtime_ms;
        myNodeInfo.air_period_tx[0] = myNodeInfo.air_period_tx[0] + airtime_ms;

        this->utilizationTX[channelUtilTXPeriod] = channelUtilization[channelUtilTXPeriod] + airtime_ms;

    } else if (reportType == RX_LOG) {
        DEBUG_MSG("AirTime - Packet received : %ums\n", airtime_ms);
        this->airtimes.periodRX[0] = this->airtimes.periodRX[0] + airtime_ms;
        myNodeInfo.air_period_rx[0] = myNodeInfo.air_period_rx[0] + airtime_ms;
    } else if (reportType == RX_ALL_LOG) {
        DEBUG_MSG("AirTime - Packet received (noise?) : %ums\n", airtime_ms);
        this->airtimes.periodRX_ALL[0] = this->airtimes.periodRX_ALL[0] + airtime_ms;
    }

    // Log all airtime type for channel utilization
    this->channelUtilization[channelUtilPeriod] = channelUtilization[channelUtilPeriod] + airtime_ms;

}

uint8_t AirTime::currentPeriodIndex()
{
    return ((getSecondsSinceBoot() / SECONDS_PER_PERIOD) % PERIODS_TO_LOG);
}

void AirTime::airtimeRotatePeriod()
{

    if (this->airtimes.lastPeriodIndex != currentPeriodIndex()) {
        //DEBUG_MSG("Rotating airtimes to a new period = %u\n", currentPeriodIndex());

        for (int i = PERIODS_TO_LOG - 2; i >= 0; --i) {
            this->airtimes.periodTX[i + 1] = this->airtimes.periodTX[i];
            this->airtimes.periodRX[i + 1] = this->airtimes.periodRX[i];
            this->airtimes.periodRX_ALL[i + 1] = this->airtimes.periodRX_ALL[i];

            myNodeInfo.air_period_tx[i + 1] = this->airtimes.periodTX[i];
            myNodeInfo.air_period_rx[i + 1] = this->airtimes.periodRX[i];
        }
        
        this->airtimes.periodTX[0] = 0;
        this->airtimes.periodRX[0] = 0;
        this->airtimes.periodRX_ALL[0] = 0;

        myNodeInfo.air_period_tx[0] = 0;
        myNodeInfo.air_period_rx[0] = 0;

        this->airtimes.lastPeriodIndex = currentPeriodIndex();
    }
}

uint32_t *AirTime::airtimeReport(reportTypes reportType)
{

    if (reportType == TX_LOG) {
        return this->airtimes.periodTX;
    } else if (reportType == RX_LOG) {
        return this->airtimes.periodRX;
    } else if (reportType == RX_ALL_LOG) {
        return this->airtimes.periodRX_ALL;
    }
    return 0;
}

uint8_t AirTime::getPeriodsToLog()
{
    return PERIODS_TO_LOG;
}

uint32_t AirTime::getSecondsPerPeriod()
{
    return SECONDS_PER_PERIOD;
}

uint32_t AirTime::getSecondsSinceBoot()
{
    return this->secSinceBoot;
}

float AirTime::channelUtilizationPercent()
{
    uint32_t sum = 0;
    for (uint32_t i = 0; i < CHANNEL_UTILIZATION_PERIODS; i++) {
        sum += this->channelUtilization[i];
        // DEBUG_MSG("ChanUtilArray %u %u\n", i, this->channelUtilization[i]);
    }

    return (float(sum) / float(CHANNEL_UTILIZATION_PERIODS * 10 * 1000)) * 100;
}

float AirTime::utilizationTXPercent()
{
    uint32_t sum = 0;
    for (uint32_t i = 0; i < MINUTES_IN_HOUR; i++) {
        sum += this->utilizationTX[i];
    }

    return (float(sum) / float(MINUTES_IN_HOUR * 10 * 1000)) * 100;
}

AirTime::AirTime() : concurrency::OSThread("AirTime") {}

int32_t AirTime::runOnce()
{
    secSinceBoot++;

    uint8_t utilPeriod = (getSecondsSinceBoot() / 10) % CHANNEL_UTILIZATION_PERIODS;
    uint8_t utilPeriodTX = (getSecondsSinceBoot() / 60) % MINUTES_IN_HOUR;

    if (firstTime) {
        airtimeRotatePeriod();


        // Init utilizationTX window to all 0
        for (uint32_t i = 0; i < MINUTES_IN_HOUR; i++) {
            this->utilizationTX[i] = 0;
        }

        // Init channelUtilization window to all 0
        for (uint32_t i = 0; i < CHANNEL_UTILIZATION_PERIODS; i++) {
            this->channelUtilization[i] = 0;
        }

        // Init airtime windows to all 0
        for (int i = 0; i < PERIODS_TO_LOG; i++) {
            this->airtimes.periodTX[i] = 0;
            this->airtimes.periodRX[i] = 0;
            this->airtimes.periodRX_ALL[i] = 0;

            //myNodeInfo.air_period_tx[i] = 0;
            //myNodeInfo.air_period_rx[i] = 0;
        }

        firstTime = false;
        lastUtilPeriod = utilPeriod;

    } else {

        // Reset the channelUtilization window when we roll over
        if (lastUtilPeriod != utilPeriod) {
            lastUtilPeriod = utilPeriod;

            this->channelUtilization[utilPeriod] = 0;
        }

        if (lastUtilPeriodTX != utilPeriodTX) {
            lastUtilPeriodTX = utilPeriodTX;

            this->utilizationTX[utilPeriodTX] = 0;
        }

        // Update channel_utilization every second.
        myNodeInfo.channel_utilization = airTime->channelUtilizationPercent();

        // Update channel_utilization every second.
        myNodeInfo.air_util_tx = airTime->utilizationTXPercent();

    }

    //DEBUG_MSG("Minutes %d TX Airtime %3.2f%\n", utilPeriodTX, airTime->utilizationTXPercent());

    return (1000 * 1);
}