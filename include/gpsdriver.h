 
#ifndef GPSDRIVER
#define GPSDRIVER
 
 
#include <Wire.h>
#include <SoftwareSerial.h>
#include <TinyGPS++.h>
#include <TinyGPSPlus.h>
/*
   This sample code demonstrates just about every built-in operation of TinyGPSPlus (TinyGPSPlus).
   It requires the use of SoftwareSerial, and assumes that you have a
   4800-baud serial GPS device hooked up on pins 4(rx) and 3(tx).
*/
static const int RXPin = 1, TXPin = 0;
static const uint32_t GPSBaud = 9600;

// The TinyGPSPlus object
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);

// For stats that happen every 5 seconds
unsigned long last = 0UL;


 // Dispatch incoming characters
  
void displayInfo() {

Serial.print(F("Location: ")); 
  if (gps.location.isValid())
  {
    Serial.print(gps.location.lat(), 6);
    Serial.print(F(","));
    Serial.print(gps.location.lng(), 6);
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.print(F("  Date/Time: "));
  if (gps.date.isValid())
  {
    Serial.print(gps.date.month());
    Serial.print(F("/"));
    Serial.print(gps.date.day());
    Serial.print(F("/"));
    Serial.print(gps.date.year());
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.print(F(" "));
  if (gps.time.isValid())
  {
    if (gps.time.hour() < 10) Serial.print(F("0"));
    Serial.print(gps.time.hour());
    Serial.print(F(":"));
    if (gps.time.minute() < 10) Serial.print(F("0"));
    Serial.print(gps.time.minute());
    Serial.print(F(":"));
    if (gps.time.second() < 10) Serial.print(F("0"));
    Serial.print(gps.time.second());
    Serial.print(F("."));
    if (gps.time.centisecond() < 10) Serial.print(F("0"));
    Serial.print(gps.time.centisecond());
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.println();




  /*screen.fillScreen(COLOR_RGB565_BLACK);

  screen.setCursor(10, 10);
  screen.print("Latitude: ");
  screen.println(gps.location.lat(), 6);

  screen.setCursor(10, 40);
  screen.print("Longitude: ");
  screen.println(gps.location.lng(), 6);

  screen.setCursor(10, 70);
  screen.print("Altitude: ");
  screen.println(gps.altitude.meters(), 2);

  screen.setCursor(10, 100);
  screen.print("Speed: ");
  screen.println(gps.speed.kmph(), 2);
    delay(1000); // Adjust the delay based on your requirements
*/
  }
  void error()
  {
    
    delay(1000); // Adjust the delay based on your requirements
  }
  



#endif