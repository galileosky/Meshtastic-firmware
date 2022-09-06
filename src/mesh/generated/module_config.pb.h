/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.6 */

#ifndef PB_MODULE_CONFIG_PB_H_INCLUDED
#define PB_MODULE_CONFIG_PB_H_INCLUDED
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Enum definitions */
typedef enum _ModuleConfig_SerialConfig_Serial_Baud { 
    ModuleConfig_SerialConfig_Serial_Baud_BAUD_Default = 0, 
    ModuleConfig_SerialConfig_Serial_Baud_BAUD_110 = 1, 
    ModuleConfig_SerialConfig_Serial_Baud_BAUD_300 = 2, 
    ModuleConfig_SerialConfig_Serial_Baud_BAUD_600 = 3, 
    ModuleConfig_SerialConfig_Serial_Baud_BAUD_1200 = 4, 
    ModuleConfig_SerialConfig_Serial_Baud_BAUD_2400 = 5, 
    ModuleConfig_SerialConfig_Serial_Baud_BAUD_4800 = 6, 
    ModuleConfig_SerialConfig_Serial_Baud_BAUD_9600 = 7, 
    ModuleConfig_SerialConfig_Serial_Baud_BAUD_19200 = 8, 
    ModuleConfig_SerialConfig_Serial_Baud_BAUD_38400 = 9, 
    ModuleConfig_SerialConfig_Serial_Baud_BAUD_57600 = 10, 
    ModuleConfig_SerialConfig_Serial_Baud_BAUD_115200 = 11, 
    ModuleConfig_SerialConfig_Serial_Baud_BAUD_230400 = 12, 
    ModuleConfig_SerialConfig_Serial_Baud_BAUD_460800 = 13, 
    ModuleConfig_SerialConfig_Serial_Baud_BAUD_576000 = 14, 
    ModuleConfig_SerialConfig_Serial_Baud_BAUD_921600 = 15 
} ModuleConfig_SerialConfig_Serial_Baud;

typedef enum _ModuleConfig_SerialConfig_Serial_Mode { 
    ModuleConfig_SerialConfig_Serial_Mode_MODE_Default = 0, 
    ModuleConfig_SerialConfig_Serial_Mode_MODE_SIMPLE = 1, 
    ModuleConfig_SerialConfig_Serial_Mode_MODE_PROTO = 2 
} ModuleConfig_SerialConfig_Serial_Mode;

typedef enum _ModuleConfig_CannedMessageConfig_InputEventChar { 
    ModuleConfig_CannedMessageConfig_InputEventChar_KEY_NONE = 0, 
    ModuleConfig_CannedMessageConfig_InputEventChar_KEY_UP = 17, 
    ModuleConfig_CannedMessageConfig_InputEventChar_KEY_DOWN = 18, 
    ModuleConfig_CannedMessageConfig_InputEventChar_KEY_LEFT = 19, 
    ModuleConfig_CannedMessageConfig_InputEventChar_KEY_RIGHT = 20, 
    ModuleConfig_CannedMessageConfig_InputEventChar_KEY_SELECT = 10, 
    ModuleConfig_CannedMessageConfig_InputEventChar_KEY_BACK = 27, 
    ModuleConfig_CannedMessageConfig_InputEventChar_KEY_CANCEL = 24 
} ModuleConfig_CannedMessageConfig_InputEventChar;

/* Struct definitions */
typedef struct _ModuleConfig_CannedMessageConfig { 
    bool rotary1_enabled;
    uint32_t inputbroker_pin_a;
    uint32_t inputbroker_pin_b;
    uint32_t inputbroker_pin_press;
    ModuleConfig_CannedMessageConfig_InputEventChar inputbroker_event_cw;
    ModuleConfig_CannedMessageConfig_InputEventChar inputbroker_event_ccw;
    ModuleConfig_CannedMessageConfig_InputEventChar inputbroker_event_press;
    bool updown1_enabled;
    bool enabled;
    char allow_input_source[16];
    bool send_bell;
} ModuleConfig_CannedMessageConfig;

typedef struct _ModuleConfig_ExternalNotificationConfig { 
    bool enabled;
    uint32_t output_ms;
    uint32_t output;
    bool active;
    bool alert_message;
    bool alert_bell;
} ModuleConfig_ExternalNotificationConfig;

typedef struct _ModuleConfig_MQTTConfig { 
    bool enabled;
    char address[32];
    char username[32];
    char password[32];
    bool encryption_enabled;
    bool json_enabled;
} ModuleConfig_MQTTConfig;

typedef struct _ModuleConfig_RangeTestConfig { 
    bool enabled;
    uint32_t sender;
    bool save;
} ModuleConfig_RangeTestConfig;

typedef struct _ModuleConfig_SerialConfig { 
    bool enabled;
    bool echo;
    uint32_t rxd;
    uint32_t txd;
    ModuleConfig_SerialConfig_Serial_Baud baud;
    uint32_t timeout;
    ModuleConfig_SerialConfig_Serial_Mode mode;
} ModuleConfig_SerialConfig;

typedef struct _ModuleConfig_StoreForwardConfig { 
    bool enabled;
    bool heartbeat;
    uint32_t records;
    uint32_t history_return_max;
    uint32_t history_return_window;
} ModuleConfig_StoreForwardConfig;

typedef struct _ModuleConfig_TelemetryConfig { 
    uint32_t device_update_interval;
    uint32_t environment_update_interval;
    bool environment_measurement_enabled;
    bool environment_screen_enabled;
    bool environment_display_fahrenheit;
} ModuleConfig_TelemetryConfig;

/* Module Config */
typedef struct _ModuleConfig { 
    pb_size_t which_payloadVariant;
    union {
        /* TODO: REPLACE */
        ModuleConfig_MQTTConfig mqtt;
        /* TODO: REPLACE */
        ModuleConfig_SerialConfig serial;
        /* TODO: REPLACE */
        ModuleConfig_ExternalNotificationConfig external_notification;
        /* TODO: REPLACE */
        ModuleConfig_StoreForwardConfig store_forward;
        /* TODO: REPLACE */
        ModuleConfig_RangeTestConfig range_test;
        /* TODO: REPLACE */
        ModuleConfig_TelemetryConfig telemetry;
        /* TODO: REPLACE */
        ModuleConfig_CannedMessageConfig canned_message;
    } payloadVariant;
} ModuleConfig;


/* Helper constants for enums */
#define _ModuleConfig_SerialConfig_Serial_Baud_MIN ModuleConfig_SerialConfig_Serial_Baud_BAUD_Default
#define _ModuleConfig_SerialConfig_Serial_Baud_MAX ModuleConfig_SerialConfig_Serial_Baud_BAUD_921600
#define _ModuleConfig_SerialConfig_Serial_Baud_ARRAYSIZE ((ModuleConfig_SerialConfig_Serial_Baud)(ModuleConfig_SerialConfig_Serial_Baud_BAUD_921600+1))

#define _ModuleConfig_SerialConfig_Serial_Mode_MIN ModuleConfig_SerialConfig_Serial_Mode_MODE_Default
#define _ModuleConfig_SerialConfig_Serial_Mode_MAX ModuleConfig_SerialConfig_Serial_Mode_MODE_PROTO
#define _ModuleConfig_SerialConfig_Serial_Mode_ARRAYSIZE ((ModuleConfig_SerialConfig_Serial_Mode)(ModuleConfig_SerialConfig_Serial_Mode_MODE_PROTO+1))

#define _ModuleConfig_CannedMessageConfig_InputEventChar_MIN ModuleConfig_CannedMessageConfig_InputEventChar_KEY_NONE
#define _ModuleConfig_CannedMessageConfig_InputEventChar_MAX ModuleConfig_CannedMessageConfig_InputEventChar_KEY_BACK
#define _ModuleConfig_CannedMessageConfig_InputEventChar_ARRAYSIZE ((ModuleConfig_CannedMessageConfig_InputEventChar)(ModuleConfig_CannedMessageConfig_InputEventChar_KEY_BACK+1))


#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define ModuleConfig_init_default                {0, {ModuleConfig_MQTTConfig_init_default}}
#define ModuleConfig_MQTTConfig_init_default     {0, "", "", "", 0, 0}
#define ModuleConfig_SerialConfig_init_default   {0, 0, 0, 0, _ModuleConfig_SerialConfig_Serial_Baud_MIN, 0, _ModuleConfig_SerialConfig_Serial_Mode_MIN}
#define ModuleConfig_ExternalNotificationConfig_init_default {0, 0, 0, 0, 0, 0}
#define ModuleConfig_StoreForwardConfig_init_default {0, 0, 0, 0, 0}
#define ModuleConfig_RangeTestConfig_init_default {0, 0, 0}
#define ModuleConfig_TelemetryConfig_init_default {0, 0, 0, 0, 0}
#define ModuleConfig_CannedMessageConfig_init_default {0, 0, 0, 0, _ModuleConfig_CannedMessageConfig_InputEventChar_MIN, _ModuleConfig_CannedMessageConfig_InputEventChar_MIN, _ModuleConfig_CannedMessageConfig_InputEventChar_MIN, 0, 0, "", 0}
#define ModuleConfig_init_zero                   {0, {ModuleConfig_MQTTConfig_init_zero}}
#define ModuleConfig_MQTTConfig_init_zero        {0, "", "", "", 0, 0}
#define ModuleConfig_SerialConfig_init_zero      {0, 0, 0, 0, _ModuleConfig_SerialConfig_Serial_Baud_MIN, 0, _ModuleConfig_SerialConfig_Serial_Mode_MIN}
#define ModuleConfig_ExternalNotificationConfig_init_zero {0, 0, 0, 0, 0, 0}
#define ModuleConfig_StoreForwardConfig_init_zero {0, 0, 0, 0, 0}
#define ModuleConfig_RangeTestConfig_init_zero   {0, 0, 0}
#define ModuleConfig_TelemetryConfig_init_zero   {0, 0, 0, 0, 0}
#define ModuleConfig_CannedMessageConfig_init_zero {0, 0, 0, 0, _ModuleConfig_CannedMessageConfig_InputEventChar_MIN, _ModuleConfig_CannedMessageConfig_InputEventChar_MIN, _ModuleConfig_CannedMessageConfig_InputEventChar_MIN, 0, 0, "", 0}

/* Field tags (for use in manual encoding/decoding) */
#define ModuleConfig_CannedMessageConfig_rotary1_enabled_tag 1
#define ModuleConfig_CannedMessageConfig_inputbroker_pin_a_tag 2
#define ModuleConfig_CannedMessageConfig_inputbroker_pin_b_tag 3
#define ModuleConfig_CannedMessageConfig_inputbroker_pin_press_tag 4
#define ModuleConfig_CannedMessageConfig_inputbroker_event_cw_tag 5
#define ModuleConfig_CannedMessageConfig_inputbroker_event_ccw_tag 6
#define ModuleConfig_CannedMessageConfig_inputbroker_event_press_tag 7
#define ModuleConfig_CannedMessageConfig_updown1_enabled_tag 8
#define ModuleConfig_CannedMessageConfig_enabled_tag 9
#define ModuleConfig_CannedMessageConfig_allow_input_source_tag 10
#define ModuleConfig_CannedMessageConfig_send_bell_tag 11
#define ModuleConfig_ExternalNotificationConfig_enabled_tag 1
#define ModuleConfig_ExternalNotificationConfig_output_ms_tag 2
#define ModuleConfig_ExternalNotificationConfig_output_tag 3
#define ModuleConfig_ExternalNotificationConfig_active_tag 4
#define ModuleConfig_ExternalNotificationConfig_alert_message_tag 5
#define ModuleConfig_ExternalNotificationConfig_alert_bell_tag 6
#define ModuleConfig_MQTTConfig_enabled_tag      1
#define ModuleConfig_MQTTConfig_address_tag      2
#define ModuleConfig_MQTTConfig_username_tag     3
#define ModuleConfig_MQTTConfig_password_tag     4
#define ModuleConfig_MQTTConfig_encryption_enabled_tag 5
#define ModuleConfig_MQTTConfig_json_enabled_tag 6
#define ModuleConfig_RangeTestConfig_enabled_tag 1
#define ModuleConfig_RangeTestConfig_sender_tag  2
#define ModuleConfig_RangeTestConfig_save_tag    3
#define ModuleConfig_SerialConfig_enabled_tag    1
#define ModuleConfig_SerialConfig_echo_tag       2
#define ModuleConfig_SerialConfig_rxd_tag        3
#define ModuleConfig_SerialConfig_txd_tag        4
#define ModuleConfig_SerialConfig_baud_tag       5
#define ModuleConfig_SerialConfig_timeout_tag    6
#define ModuleConfig_SerialConfig_mode_tag       7
#define ModuleConfig_StoreForwardConfig_enabled_tag 1
#define ModuleConfig_StoreForwardConfig_heartbeat_tag 2
#define ModuleConfig_StoreForwardConfig_records_tag 3
#define ModuleConfig_StoreForwardConfig_history_return_max_tag 4
#define ModuleConfig_StoreForwardConfig_history_return_window_tag 5
#define ModuleConfig_TelemetryConfig_device_update_interval_tag 1
#define ModuleConfig_TelemetryConfig_environment_update_interval_tag 2
#define ModuleConfig_TelemetryConfig_environment_measurement_enabled_tag 3
#define ModuleConfig_TelemetryConfig_environment_screen_enabled_tag 4
#define ModuleConfig_TelemetryConfig_environment_display_fahrenheit_tag 7
#define ModuleConfig_mqtt_tag                    1
#define ModuleConfig_serial_tag                  2
#define ModuleConfig_external_notification_tag   3
#define ModuleConfig_store_forward_tag           4
#define ModuleConfig_range_test_tag              5
#define ModuleConfig_telemetry_tag               6
#define ModuleConfig_canned_message_tag          7

/* Struct field encoding specification for nanopb */
#define ModuleConfig_FIELDLIST(X, a) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payloadVariant,mqtt,payloadVariant.mqtt),   1) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payloadVariant,serial,payloadVariant.serial),   2) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payloadVariant,external_notification,payloadVariant.external_notification),   3) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payloadVariant,store_forward,payloadVariant.store_forward),   4) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payloadVariant,range_test,payloadVariant.range_test),   5) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payloadVariant,telemetry,payloadVariant.telemetry),   6) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payloadVariant,canned_message,payloadVariant.canned_message),   7)
#define ModuleConfig_CALLBACK NULL
#define ModuleConfig_DEFAULT NULL
#define ModuleConfig_payloadVariant_mqtt_MSGTYPE ModuleConfig_MQTTConfig
#define ModuleConfig_payloadVariant_serial_MSGTYPE ModuleConfig_SerialConfig
#define ModuleConfig_payloadVariant_external_notification_MSGTYPE ModuleConfig_ExternalNotificationConfig
#define ModuleConfig_payloadVariant_store_forward_MSGTYPE ModuleConfig_StoreForwardConfig
#define ModuleConfig_payloadVariant_range_test_MSGTYPE ModuleConfig_RangeTestConfig
#define ModuleConfig_payloadVariant_telemetry_MSGTYPE ModuleConfig_TelemetryConfig
#define ModuleConfig_payloadVariant_canned_message_MSGTYPE ModuleConfig_CannedMessageConfig

#define ModuleConfig_MQTTConfig_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, BOOL,     enabled,           1) \
X(a, STATIC,   SINGULAR, STRING,   address,           2) \
X(a, STATIC,   SINGULAR, STRING,   username,          3) \
X(a, STATIC,   SINGULAR, STRING,   password,          4) \
X(a, STATIC,   SINGULAR, BOOL,     encryption_enabled,   5) \
X(a, STATIC,   SINGULAR, BOOL,     json_enabled,      6)
#define ModuleConfig_MQTTConfig_CALLBACK NULL
#define ModuleConfig_MQTTConfig_DEFAULT NULL

#define ModuleConfig_SerialConfig_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, BOOL,     enabled,           1) \
X(a, STATIC,   SINGULAR, BOOL,     echo,              2) \
X(a, STATIC,   SINGULAR, UINT32,   rxd,               3) \
X(a, STATIC,   SINGULAR, UINT32,   txd,               4) \
X(a, STATIC,   SINGULAR, UENUM,    baud,              5) \
X(a, STATIC,   SINGULAR, UINT32,   timeout,           6) \
X(a, STATIC,   SINGULAR, UENUM,    mode,              7)
#define ModuleConfig_SerialConfig_CALLBACK NULL
#define ModuleConfig_SerialConfig_DEFAULT NULL

#define ModuleConfig_ExternalNotificationConfig_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, BOOL,     enabled,           1) \
X(a, STATIC,   SINGULAR, UINT32,   output_ms,         2) \
X(a, STATIC,   SINGULAR, UINT32,   output,            3) \
X(a, STATIC,   SINGULAR, BOOL,     active,            4) \
X(a, STATIC,   SINGULAR, BOOL,     alert_message,     5) \
X(a, STATIC,   SINGULAR, BOOL,     alert_bell,        6)
#define ModuleConfig_ExternalNotificationConfig_CALLBACK NULL
#define ModuleConfig_ExternalNotificationConfig_DEFAULT NULL

#define ModuleConfig_StoreForwardConfig_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, BOOL,     enabled,           1) \
X(a, STATIC,   SINGULAR, BOOL,     heartbeat,         2) \
X(a, STATIC,   SINGULAR, UINT32,   records,           3) \
X(a, STATIC,   SINGULAR, UINT32,   history_return_max,   4) \
X(a, STATIC,   SINGULAR, UINT32,   history_return_window,   5)
#define ModuleConfig_StoreForwardConfig_CALLBACK NULL
#define ModuleConfig_StoreForwardConfig_DEFAULT NULL

#define ModuleConfig_RangeTestConfig_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, BOOL,     enabled,           1) \
X(a, STATIC,   SINGULAR, UINT32,   sender,            2) \
X(a, STATIC,   SINGULAR, BOOL,     save,              3)
#define ModuleConfig_RangeTestConfig_CALLBACK NULL
#define ModuleConfig_RangeTestConfig_DEFAULT NULL

#define ModuleConfig_TelemetryConfig_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   device_update_interval,   1) \
X(a, STATIC,   SINGULAR, UINT32,   environment_update_interval,   2) \
X(a, STATIC,   SINGULAR, BOOL,     environment_measurement_enabled,   3) \
X(a, STATIC,   SINGULAR, BOOL,     environment_screen_enabled,   4) \
X(a, STATIC,   SINGULAR, BOOL,     environment_display_fahrenheit,   7)
#define ModuleConfig_TelemetryConfig_CALLBACK NULL
#define ModuleConfig_TelemetryConfig_DEFAULT NULL

#define ModuleConfig_CannedMessageConfig_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, BOOL,     rotary1_enabled,   1) \
X(a, STATIC,   SINGULAR, UINT32,   inputbroker_pin_a,   2) \
X(a, STATIC,   SINGULAR, UINT32,   inputbroker_pin_b,   3) \
X(a, STATIC,   SINGULAR, UINT32,   inputbroker_pin_press,   4) \
X(a, STATIC,   SINGULAR, UENUM,    inputbroker_event_cw,   5) \
X(a, STATIC,   SINGULAR, UENUM,    inputbroker_event_ccw,   6) \
X(a, STATIC,   SINGULAR, UENUM,    inputbroker_event_press,   7) \
X(a, STATIC,   SINGULAR, BOOL,     updown1_enabled,   8) \
X(a, STATIC,   SINGULAR, BOOL,     enabled,           9) \
X(a, STATIC,   SINGULAR, STRING,   allow_input_source,  10) \
X(a, STATIC,   SINGULAR, BOOL,     send_bell,        11)
#define ModuleConfig_CannedMessageConfig_CALLBACK NULL
#define ModuleConfig_CannedMessageConfig_DEFAULT NULL

extern const pb_msgdesc_t ModuleConfig_msg;
extern const pb_msgdesc_t ModuleConfig_MQTTConfig_msg;
extern const pb_msgdesc_t ModuleConfig_SerialConfig_msg;
extern const pb_msgdesc_t ModuleConfig_ExternalNotificationConfig_msg;
extern const pb_msgdesc_t ModuleConfig_StoreForwardConfig_msg;
extern const pb_msgdesc_t ModuleConfig_RangeTestConfig_msg;
extern const pb_msgdesc_t ModuleConfig_TelemetryConfig_msg;
extern const pb_msgdesc_t ModuleConfig_CannedMessageConfig_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define ModuleConfig_fields &ModuleConfig_msg
#define ModuleConfig_MQTTConfig_fields &ModuleConfig_MQTTConfig_msg
#define ModuleConfig_SerialConfig_fields &ModuleConfig_SerialConfig_msg
#define ModuleConfig_ExternalNotificationConfig_fields &ModuleConfig_ExternalNotificationConfig_msg
#define ModuleConfig_StoreForwardConfig_fields &ModuleConfig_StoreForwardConfig_msg
#define ModuleConfig_RangeTestConfig_fields &ModuleConfig_RangeTestConfig_msg
#define ModuleConfig_TelemetryConfig_fields &ModuleConfig_TelemetryConfig_msg
#define ModuleConfig_CannedMessageConfig_fields &ModuleConfig_CannedMessageConfig_msg

/* Maximum encoded size of messages (where known) */
#define ModuleConfig_CannedMessageConfig_size    49
#define ModuleConfig_ExternalNotificationConfig_size 20
#define ModuleConfig_MQTTConfig_size             105
#define ModuleConfig_RangeTestConfig_size        10
#define ModuleConfig_SerialConfig_size           26
#define ModuleConfig_StoreForwardConfig_size     22
#define ModuleConfig_TelemetryConfig_size        18
#define ModuleConfig_size                        107

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
