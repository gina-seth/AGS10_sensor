#include <AGS10.h>
#include <Wire.h>
#include <Arduino.h>

// declare sensor 
AGS10 sensor = AGS10();

// declare data variables
int version, resist;

void setup() {
  // begin a serial monitor 
  Serial.begin(9600);

  //  initialize sensor 
  sensor.begin();

  version = sensor.readVersion();
  resist = sensor.readResist();

  Serial.println("----------------------------------");
  Serial.print("Firmware version: ");
  Serial.println(version);
  Serial.println("----------------------------------");
  Serial.print("Current Resistance (0.1kR): ");
  Serial.println(resist);
  Serial.println("----------------------------------");
}

void loop() {
  // this code only needs to run once

}
