#include <declarations.h>




void setup()
{
  Serial.begin(115200);
  ss.begin(GPSBaud);
  Serial.println(ss);
  connectToWiFi();
  setDateTime();
  
  

}
void loop()
{
  // This sketch displays information every time a new sentence is correctly encoded.
  while (ss.available() > 0)
  {
    if (gps.encode(ss.read()))
    {
      displayInfo();
     //lastSeenLoc();
      connectToMQTT();
      publishGPSData();
      deepSleep();
      onWakeup();
     /* Serial.println("Last Seen Lat:");
      Serial.println(lastloclat);
      Serial.println("Last Seen Lng:");
      Serial.println(lastloclng);*/
    }       
  }

  if (millis() > 5000 && gps.charsProcessed() < 10)
  {
    Serial.println(F("No GPS detected: check wiring."));
    while(true);
  }

 


}

