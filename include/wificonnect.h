#ifndef WIFICONNECT
#define WIFICONNECT

#include <WiFi.h>



const char* ssid = "kronos";
const char* password = "Cursed4252!";

void connectToWiFi() {
  Serial.print("Connecting to Wi-Fi");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("\nConnected to Wi-Fi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}



#endif 
