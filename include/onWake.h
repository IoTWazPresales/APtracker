#ifndef ONWAKE
#define ONWAKE

#include <declarations.h>

void onWakeup(){

  Serial.begin(115200);
  ss.begin(GPSBaud);
  Serial.println(ss);
  connectToWiFi();
  setDateTime();
  Serial.println("woken Up");
  
}




#endif