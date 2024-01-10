#ifndef GPSDATAPUBLISHER
#define GPSDATAPUBLISHER
#include <mqttconnecter.h>
#include <lastseen.h>

void publishGPSData() {

 char gpsData[100];

 
  snprintf(gpsData, sizeof(gpsData), "{\"latitude\": %d, \"longitude\": %d}", lastloclat, lastloclng);

  // Publish data to MQTT topic
  char topic[50];
  snprintf(topic, sizeof(topic), "testtopic");
  client.publish(topic, gpsData);

  
}



#endif 