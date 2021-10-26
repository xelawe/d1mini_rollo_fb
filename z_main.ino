
void setup() {
  cy_serial::start(__FILE__);

  init_zb40();
  wifi_init(gc_hostname);
  delay(500);

  init_ota(gv_clientname);

  init_mqtt_local( );

  init_sched();

  Serial.println(F("done Setup"));
}

void loop() {
  check_ota();

  check_mqtt_reset();

  if ( gv_1s ) {
    //get_LDR_val();

    gv_1s = false;
  }

  if ( gv_1m ) {
    //pub_sens(get_LDR_val());

    gv_1m = false;
  }


  delay(100);
}
