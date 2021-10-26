#define gc_cnt_fb_pins 3

//ZB40 config
// pinmapping HCS361 keeloq chip<->ESP node mcu (0,1,2,3)
const int FB_PINS[] = {D5, D1, D2}; 
enum gt_cmd_i { CMD_NONE, CMD_UP, CMD_DOWN, CMD_STOP, CMD_MID, CMD_VENT };
enum gt_shutter_i { SHUTTER_ALL, SHUTTER_1, SHUTTER_2, SHUTTER_3 };

byte gv_fb_pin_nbr;
