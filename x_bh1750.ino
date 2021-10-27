#include <Wire.h>
#include <BH1750.h>


// Create the Lightsensor instance
BH1750 lightMeter(0x5c);//(0x23);
float gv_lux;

boolean gv_bh1750_ok;
