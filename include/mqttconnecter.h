#ifndef MQTTCONNECTER
#define MQTTCONNECTER

#include "mqttcredentials.h"  // Include your MQTT credentials file
#include <PubSubClient.h>
#include <WiFi.h>
#include <LittleFS.h>




WiFiClient wifiClient;
PubSubClient client(wifiClient);

  // Handle incoming MQTT messages if needed
  void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  
  }


void connectToMQTT() {


  client.setServer(MQTT_SERVER, MQTT_PORT);
  client.setCallback(callback);

  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
    
    if (client.connect(MQTT_CLIENT_ID, MQTT_USER, MQTT_PASSWORD)) {
      Serial.println("Connected to MQTT!");

      
    } else {
      Serial.print("Failed, rc=");
      Serial.print(client.state());
      Serial.println(" Retrying in 5 seconds...");
      delay(5000);
    }
  }
}

#endif 