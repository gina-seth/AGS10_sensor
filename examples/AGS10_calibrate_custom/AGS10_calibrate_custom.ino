#include <AGS10.h>
#include <Wire.h>
#include <Arduino.h>

// declare sensor 
AGS10 sensor = AGS10();

// declare calibration variables
uint8_t calib_CMD1 = 0xFF;
uint8_t calib_CMD2 = 0xFF;

void setup() {
  //  begin a serial monitor 
  Serial.begin(9600);

  //  initialize sensor 
  sensor.begin();

  /* calibrate the sensor

     this function works like such:
     xxx.calibrateCust(ResistanceByte1, ResistanceByte2);

     the two values are the bytes that will make up the resistanace that you will
     set for the sensor. see the AGS10 datasheet for more info about these values: 
     http://www.aosong.com/en/products-86.html

     in the future, i may just add the math and such into the library, until then...
  */
  sensor.calibrateCust(calib_CMD1,calib_CMD2);

}

void loop() {
  //  the code only needs to run once

}
