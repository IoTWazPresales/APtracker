#ifndef SLEEP
#define SLEEP
#include <WiFi.h>
#include <esp_wifi.h>
#include <onWake.h>

#define TIME_TO_SLEEP 20   // Sleep time in seconds
#define uS_TO_S_FACTOR 1000000  // Conversion factor for micro-seconds to seconds

void deepSleep(){

Serial.println("Good Night");
esp_wifi_stop();
esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);
esp_deep_sleep_start();


}
#endif