// AGS10.h

// This is a library for the AGS10 sensor // It measures the total volatile organic compounds (TVOC) in the air // The sensor uses I2C communication protocol

#ifndef AGS10_H 
#define AGS10_H

#include <Arduino.h> 
#include <Wire.h>

// Define the I2C address of the sensor
#define AGS10_ADDR 0x1A

// Define the register addresses
#define TVOC_REG 0x00
#define VERS_REG 0x11
#define RESIST_REG 0x20
#define CALIB_REG 0x01

// Define the calibration commands
#define CALIB_CMD1 0x00
#define CALIB_CMD2 0x0C
#define CALIB_FACT 0xFF
#define CALIB_ZERO 0x00

class AGS10 { 
  
  public:

    AGS10();  // Constructor 
    void begin(); // Initialize the sensor
    void calibrate(bool select); // Calibrate the sensor
    void reset(); // Reset the sensor
    int readResist(); // Read the current resistance of the sensor in 0.1 kO
    int readVersion();  // Read the sensor's current firmware version 
    int readTVOC(); // Read the TVOC value in ppb
    u8 Calc_CRC8(u8 *dat, u8 Num);


  private: 

    int _tvoc; // Variable to store the TVOC value 
    int _version; // Variable to store the version value 
    int _resist;  // Variable to store the resistance value
    int _status; // Variable to store the status of the sensor [INACTIVE]
    u8 _crc;

  };

#endif