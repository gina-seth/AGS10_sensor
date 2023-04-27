//  AGS10.cpp

#include "AGS10.h"


uint8_t AGS10::Calc_CRC8(uint8_t *dat, uint8_t Num)
{
  uint8_t i,byte1,crc=0xFF;
  for(byte1=0; byte1<Num; byte1++)
  {
    crc^=(dat[byte1]);
    for(i=0;i<8;i++)
    {
      if(crc & 0x80) crc=(crc<<1)^0x31;
      else crc=(crc<<1);
    }
  }
  return crc;
}



AGS10::AGS10()
{
  _tvoc = 0;
}

void AGS10::begin()
{
  Wire.begin();
}

void AGS10::calibrateFact()
{
  uint8_t data[4] = {CALIB_CMD1, CALIB_CMD2, CALIB_FACT, CALIB_FACT};
  _crc = Calc_CRC8(uint8_t(data), uint8_t(0x01));
  Wire.beginTransmission(AGS10_ADDR);
  Wire.write(CALIB_REG);
  Wire.write(CALIB_CMD1);
  Wire.write(CALIB_CMD2);
  Wire.write(CALIB_FACT);
  Wire.write(CALIB_FACT);
  Wire.write(_crc);
  Wire.endTransmission();
}
  
void AGS10::calibrateCust(uint8_t CALIB_RES1, uint8_t CALIB_RES2)
{
	
    byte data[4] = {CALIB_CMD1, CALIB_CMD2, CALIB_RES1, CALIB_RES2};
    _crc = Calc_CRC8(data, 0x01);
    Wire.beginTransmission(AGS10_ADDR);
    Wire.write(CALIB_REG);
    Wire.write(CALIB_CMD1);
    Wire.write(CALIB_CMD2);
    Wire.write(CALIB_RES1);
    Wire.write(CALIB_RES2);
    Wire.write(_crc);
    Wire.endTransmission();
}
  


void AGS10::setAddress(uint8_t newAddr)
{
  uint8_t newAddrInv = (uint8_t) ~newAddr;
  uint8_t data[4] = {newAddr, newAddrInv, newAddr, newAddrInv}; 
  _crc = Calc_CRC8(data, 0x01);
  Wire.beginTransmission(AGS10_ADDR);
  Wire.write(SLAVE_REG);
  Wire.write(newAddr);
  Wire.write(newAddrInv);
  Wire.write(newAddr);
  Wire.write(newAddrInv);
  Wire.write(_crc);
  Wire.endTransmission();
}

int AGS10::readVersion()
{
  Wire.beginTransmission(AGS10_ADDR);
  Wire.write(VERS_REG);
  Wire.endTransmission();
  Wire.requestFrom(AGS10_ADDR, 5);

  if (Wire.available() == 5)  {
    byte reserved1 = Wire.read();
    byte reserved2 = Wire.read();
    byte reserved3 = Wire.read();
    byte version = Wire.read();
    byte crcByte = Wire.read();

    _version = version;

    return _version;
  }
}

int AGS10::readResist()
{
  Wire.beginTransmission(AGS10_ADDR);
  Wire.write(RESIST_REG);
  Wire.endTransmission();

  Wire.requestFrom(AGS10_ADDR, 5);

  if (Wire.available() == 5)  {
    byte resistByteA = Wire.read();
    byte resistByteB = Wire.read();
    byte resistByteC = Wire.read();
    byte resistByteD = Wire.read();
    byte crcByte = Wire.read();

    _resist = (resistByteA << 24) | (resistByteB << 16) | (resistByteC << 8) | resistByteD;
    
    return _resist;
  }
}

int AGS10::readTVOC()
{
  Wire.beginTransmission(AGS10_ADDR);
  Wire.write(TVOC_REG);
  Wire.endTransmission();

  Wire.requestFrom(AGS10_ADDR, 5);

  if (Wire.available() == 5)  {
    byte statusByte = Wire.read();
    byte tvocByteA = Wire.read();
    byte tvocByteB = Wire.read();
    byte tvocByteC = Wire.read();
    byte crcByte = Wire.read();

    int statusBit = (statusByte & 0x01) != 0;
    _status = statusBit;
    _tvoc = (tvocByteA << 16) | (tvocByteB << 8) | tvocByteC;
  
    return _tvoc;
  }
}

