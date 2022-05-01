#include "Wire.h"
#include "Arduino.h"
#include "TCA9548.h"

bool CAM_TCA9548::begin(uint8_t ADDRESS = 0x70) {
  Wire.begin();
  _address = ADDRESS;
  Wire.beginTransmission(_address);
  setChannel(0);
  return test_I2C(_address);
}

void CAM_TCA9548::setChannel(uint8_t Channel) {
  _channel = Channel;
  write(_channel);
}

uint8_t CAM_TCA9548::getChanal(void) {
  return _channel;
}


bool CAM_TCA9548::ifInList(uint8_t ADDRESS) {
  bool Fund = false;
  for (int counter = 0; counter < sizeof(_devAddress); counter++) {
    if (_devAddress[counter] == ADDRESS)
      Fund = true;
  }
  return Fund;
}

String CAM_TCA9548::scan() {
  String output = "";
  output += "tca9548 Scan\n";
  uint8_t counter3 = 0;
  uint8_t Channel = 0;
  for (int counter1 = 0; counter1 < 8; counter1++) {
    for (int counter2 = 0; counter2 < 16; counter2++) {
      uint8_t ADDRESS = (counter1 * 16) +  counter2;
      if (test_device(0x00, ADDRESS) == true) {
        // add
        _devAddress[counter3] = ADDRESS;
        counter3++;
        if (counter3 == 1) {
          output += "Global (Ch. 0): ";
          output += "\n";
        }
        output += " -  Address: 0x";
        if (ADDRESS < 16)
          output += "0";
        output += String(ADDRESS, HEX);
        output += "\n";
      }
    }
  }
  for (Channel  = 0; Channel  < 8; Channel ++)  {
    counter3 = 0;
    for (int counter1 = 0; counter1 < 8; counter1++) {
      for (int counter2 = 0; counter2 < 16; counter2++) {
        uint8_t ADDRESS = (counter1 * 16) +  counter2;
        if ((!ifInList(ADDRESS)) && (test_device(0x01 << Channel, ADDRESS) == true)) {
          counter3++;
          if (counter3 == 1) {
            output += "Channel: ";
            output += Channel + 1;
            output += "\n";
          }
          output += " -  Address: 0x";
          if (ADDRESS < 16)
            output += "0";
          output += String(ADDRESS, HEX);
          output += "\n";
        }
      }
    }
  }
  return output;
}

bool CAM_TCA9548::test_device(uint8_t Channel, uint8_t ADDRESS) {
  setChannel(Channel);
  return test_I2C(ADDRESS);
}

bool CAM_TCA9548::test_I2C(uint8_t ADDRESS) {
  Wire.beginTransmission(ADDRESS);
  if (Wire.endTransmission() == 0)
    return true;
  else
    return false;
}

uint8_t CAM_TCA9548::write(uint8_t value) {
  Wire.beginTransmission(_address);
  Wire.write(value);
  return Wire.endTransmission();
}
