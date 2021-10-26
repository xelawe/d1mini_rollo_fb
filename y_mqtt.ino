char *get_stopic_ix( int ix ) {
  strcpy_P(gv_sbuffer, (char*)pgm_read_dword(&(gt_stopic_gw60[ix])));
  //strcpy_P(gv_buffer, );
  return gv_sbuffer;
}

char *get_cmd_ix( int ix ) {
  strcpy_P(gv_pbuffer, (char*)pgm_read_dword(&(gt_cmd[ix])));
  //strcpy_P(gv_buffer, );
  return gv_pbuffer;
}

void pub_stat(int ix, int cmd) {

  // bei ix == 0 --> alle auf cmd setzen!

  if (!client.publish(mqtt_GetTopic_P(gv_ptopic, 1, gv_clientname, get_stopic_ix(ix)), get_cmd_ix(cmd), true)) {
    DebugPrintln(F("pub failed!"));
  } else {
    DebugPrintln(F("pub ok!"));
  }

}

void callback_mqtt_index(int shutter_index, byte* payload, unsigned int length) {
  bool cmd_valid = true;
  String message_string = "";

  for (int i = 0; i < length; i++) {
    DebugPrint((char)payload[i]);
    //fill up the message string
    message_string.concat((char)payload[i]);
  }
  DebugPrintln();

  //map payload / commands
  int shutter_cmd = CMD_NONE;
  if (message_string.equalsIgnoreCase(F("up"))) {
    shutter_cmd = CMD_UP;
  }
  else if (message_string.equalsIgnoreCase(F("down"))) {
    shutter_cmd = CMD_DOWN;
  }
  else if (message_string.equalsIgnoreCase(F("stop"))) {
    shutter_cmd = CMD_STOP;
  }
  else if (message_string.equalsIgnoreCase(F("mid"))) {
    shutter_cmd = CMD_MID;
  }
  else if (message_string.equalsIgnoreCase(F("vent"))) {
    shutter_cmd = CMD_VENT;
  }
  else {
    DebugPrint(F("Received illegal command message: "));
    DebugPrintln(message_string.c_str());
    cmd_valid = false;
  }

  if (cmd_valid) {
    send_FB_command(shutter_index, shutter_cmd);
    // To be sure, send it a second time
    //send_ZB40_command(shutter_index, shutter_cmd);

    pub_stat(shutter_index, shutter_cmd);
  }

}

void callback_mqtt_0(char* topic, byte* payload, unsigned int length) {
  DebugPrintln(F("Callback 0 - SHUTTER_ALL"));
  callback_mqtt_index(SHUTTER_ALL, payload, length);
}

void callback_mqtt_1(char* topic, byte* payload, unsigned int length) {
  DebugPrintln(F("Callback 1 - SHUTTER_1"));
  callback_mqtt_index(SHUTTER_1, payload, length);
}

void callback_mqtt_2(char* topic, byte* payload, unsigned int length) {
  DebugPrintln(F("Callback 2 - SHUTTER_2"));
  callback_mqtt_index(SHUTTER_2, payload, length);
}

void callback_mqtt_3(char* topic, byte* payload, unsigned int length) {
  DebugPrintln(F("Callback 3 - SHUTTER_3"));
  callback_mqtt_index(SHUTTER_3, payload, length);
}

void init_mqtt_local( ) {

  init_mqtt(gv_clientname);

  add_subtopic(mqtt_GetTopic_P(gv_stopic_0, 0, gv_clientname, get_stopic_ix(0)), callback_mqtt_0);
  add_subtopic(mqtt_GetTopic_P(gv_stopic_1, 0, gv_clientname, get_stopic_ix(1)), callback_mqtt_1);
  add_subtopic(mqtt_GetTopic_P(gv_stopic_2, 0, gv_clientname, get_stopic_ix(2)), callback_mqtt_2);
  add_subtopic(mqtt_GetTopic_P(gv_stopic_3, 0, gv_clientname, get_stopic_ix(3)), callback_mqtt_3);
}
