#include <AGS10.h>
#include <Wire.h>
#include <Arduino.h>

// declare sensor 
AGS10 sensor = AGS10();


void setup() {
  //  begin a serial monitor 
  Serial.begin(9600);

  //  initialize sensor 
  sensor.begin();

  // calibrate the sensor to factory resistance
  sensor.calibrateFact();

}

void loop() {
  //  the code only needs to run once

}
