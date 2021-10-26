#include "cy_mqtt_v1.h"

char gv_stopic_0[MQTT_TOPSZ];
char gv_stopic_1[MQTT_TOPSZ];
char gv_stopic_2[MQTT_TOPSZ];
char gv_stopic_3[MQTT_TOPSZ];

const char gc_stopic_0[] PROGMEM = "0";
const char gc_stopic_1[] PROGMEM = "1";
const char gc_stopic_2[] PROGMEM = "2";
const char gc_stopic_3[] PROGMEM = "3";
const char* const gt_stopic_gw60[] PROGMEM = { gc_stopic_0, gc_stopic_1, gc_stopic_2, gc_stopic_3 };
char gv_sbuffer[7];// buffer for reading the string to (needs to be large enough to take the longest string

char gv_ptopic[MQTT_TOPSZ];
char gv_pbuffer[5];// buffer for reading the string to (needs to be large enough to take the longest string

const char gc_cmd_none[] PROGMEM = "none";
const char gc_cmd_up[] PROGMEM = "up";
const char gc_cmd_down[] PROGMEM = "down";
const char gc_cmd_stop[] PROGMEM = "stop";
const char gc_cmd_mid[] PROGMEM = "mid";
const char gc_cmd_vent[] PROGMEM = "vent";
const char* const gt_cmd[] PROGMEM = { gc_cmd_none, gc_cmd_up, gc_cmd_down, gc_cmd_stop, gc_cmd_mid, gc_cmd_vent };
