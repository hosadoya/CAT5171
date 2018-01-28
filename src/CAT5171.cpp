#include "Arduino.h"
#include "CAT5171.h"
#include <Wire.h>

CAT5171::CAT5171()
{
  _address = ADDRESS0;

   Wire.begin();
}

void CAT5171::setWiper(byte position)
{
  Wire.beginTransmission(_address);
  
  Wire.write(B00000000);
  Wire.write(position);
  Wire.endTransmission();
}

byte CAT5171::getWiper()
{
  byte pos = 0;
  
  Wire.requestFrom(B0101100, 1);
  
  while(Wire.available())
  { 
    pos = Wire.read();
  }
  
  return pos;
}

void CAT5171::shutDown()
{  
  Wire.beginTransmission(_address);
  
  Wire.write(B00100000);
  Wire.write((byte)0);
  Wire.endTransmission();
}

void CAT5171::switchToSecondDevice()
{
  _address = ADDRESS1;
}
