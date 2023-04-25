#include <AGS10.h>
#include <Wire.h>
#include <Arduino.h>

// declare sensor 
AGS10 sensor = AGS10();

// declare data variable
int tvoc;

void setup() {
  // begin a serial monitor
  Serial.begin(9600);

  //  initialize sensor 
  sensor.begin();


}

void loop() {
  //  read TVOC sensor data every 1.6 seconds, according to datasheet max speed is 1.5 seconds/reading
  tvoc = sensor.readTVOC();
  Serial.println(tvoc);
  delay(1600);

}
