#include <Wire.h>
#include "TCA9548.h"

bool CAP_TCA9548::begin(uint8_t ADDRESS = 0x70) {
  Wire.begin();
  _address = ADDRESS;
  Wire.beginTransmission(_address);
  setChannel(0);
  return test_I2C(_address);
}

void CAP_TCA9548::setChannel(uint8_t Channel) {
  _channel = Channel;
  write(_channel);
}

uint8_t CAP_TCA9548::getChanal(void) {
  return _channel;
}

String CAP_TCA9548::scan() {
  String output = "";
  for (uint8_t Channel  = 0; Channel  < 8; Channel ++)  {
    for (int counter1 = 0; counter1 < 8; counter1++) {
      for (int counter2 = 0; counter2 < 16; counter2++) {
        uint8_t ADDRESS = (counter1 * 16) +  counter2;
        if ((ADDRESS != _address) && (test_device(0x01 << Channel, ADDRESS) == true)) {
          output += "Channel: ";
          if (Channel+1<16)
            output += "0";
          output += Channel+1;
          output += " -  Address: 0x";
          if (ADDRESS<16)
            output += "0";
          output += String(ADDRESS, HEX);
          output += ",\n";
        }
      }
    }
  }
  return output;
}

bool CAP_TCA9548::test_device(uint8_t Channel, uint8_t ADDRESS) {
  setChannel(Channel);
  return test_I2C(ADDRESS);
}

bool CAP_TCA9548::test_I2C(uint8_t ADDRESS) {
  Wire.beginTransmission(ADDRESS);
  if (Wire.endTransmission() == 0)
    return true;
  else
    return false;
}

uint8_t CAP_TCA9548::write(uint8_t value) {
  Wire.beginTransmission(_address);
  Wire.write(value);
  return Wire.endTransmission();
}

