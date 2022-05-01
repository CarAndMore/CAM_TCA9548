
#ifndef CAP_TCA9548_h
#define CAP_TCA9548_h
#include "Arduino.h"

class CAM_TCA9548 {
  public:
    bool begin(uint8_t ADDRESS = 0x70);

    void setChannel(uint8_t Channel);
    uint8_t getChanal(void);
    bool test_device(uint8_t Channel, uint8_t ADDRESS);
    String scan(void);
  private:
    uint8_t _address, _channel;
    uint8_t _devAddress[128];
    
    bool test_I2C(uint8_t ADDRESS);
    bool ifInList(uint8_t ADDRESS);
    uint8_t write(uint8_t value);
};
#endif
