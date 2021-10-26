

//FB functions
void send_FB_command(int shutter, int command) {

  byte lv_repeat = 0;

  switch (command) {
    case CMD_STOP:
      gv_fb_pin_nbr = 1;
      lv_repeat = 1;
      break;
    case CMD_UP:
      gv_fb_pin_nbr = 2;
      lv_repeat = 1;
      break;
    case CMD_DOWN:
      gv_fb_pin_nbr = 0;
      lv_repeat = 1;
      break;
    case CMD_MID:
      gv_fb_pin_nbr = 0;
      lv_repeat = 2;
      break;
    case CMD_VENT:
      gv_fb_pin_nbr = 2;
      lv_repeat = 2;
      break;
    default:
      return;
      break;
  }

  Serial.print("Sending... [");
  for (int i = 0; i < lv_repeat; i++) {
    digitalWrite(FB_PINS[gv_fb_pin_nbr], LOW);
    Serial.print(gv_fb_pin_nbr);
    delay(135);
    digitalWrite(FB_PINS[gv_fb_pin_nbr], HIGH);
    delay(150);
  }

  Serial.println("]");

}

void init_zb40() {

  Serial.print("Init Pins... [ ");
  //set the outputs accordingly
  for (int i = 0; i < gc_cnt_fb_pins; i++) {
    pinMode(FB_PINS[i], OUTPUT);
    digitalWrite(FB_PINS[i], HIGH);
    Serial.print(FB_PINS[i]);
    Serial.print(" ");
  }
  Serial.println("]");

}
