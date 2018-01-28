#ifndef CAT5171_h
#define CAT5171_h

#include "Arduino.h"

#define ADDRESS0 B0101100
#define ADDRESS1 B0101101

class CAT5171
{
  public:
    CAT5171();

    // Set wiper position (0-255)
    void setWiper(byte position);

    // Get the current wiper position
    byte getWiper();

    // Shut down the device. Wiper = B, A is open circuit
    void shutDown();

    // Switch to the second I2C address supported by this device (maximum of 2 of this devices can be on the same I2C bus)
    void switchToSecondDevice();

  private:
    // The currently selected device address
    byte _address;
};

#endif