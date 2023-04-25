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
#define SLAVE_REG 0x21

// Define the calibration commands
#define CALIB_CMD1 0x00
#define CALIB_CMD2 0x0C
#define CALIB_FACT 0xFF
#define CALIB_ZERO 0x00

class AGS10 { 
  
  public:

    AGS10();  // Constructor 
    void begin(); // Initialize the sensor
    void calibrateFact(); // Calibrate the sensor
	void calibrateCust(uint8_t CALIB_RES1, uint8_t CALIB_RES2); // Calibrate the sensor using a custom resistance value (measured in 0.1kΩ)
    void setAddress(uint8_t newAddr); // Set the sensor's i2c addr to have more than one sensor on the same bus
    int readResist(); // Read the current resistance of the sensor in 0.1 kO
    int readVersion();  // Read the sensor's current firmware version 
    int readTVOC(); // Read the TVOC value in ppb
    uint8_t Calc_CRC8(uint8_t *dat, uint8_t Num); 


  private: 

    int _tvoc; // Variable to store the TVOC value 
    int _version; // Variable to store the version value 
    int _resist;  // Variable to store the resistance value
    int _status; // Variable to store the status of the sensor [INACTIVE]
    byte _crc;

  };

#endif
