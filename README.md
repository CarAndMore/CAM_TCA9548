# TCA9548

# example

## Simple Scanner

```cpp
#define TCA9548_addr 0x70

#include "TCA9548.h"

CAP_TCA9548 tca9548;

void setup() {
  Serial.begin(9600);
  if (!tca9548.begin( TCA9548_addr )) {
    Serial.println("tca9548 not Found");
    while (1) {}
  }
  Serial.println("Start tca9548 Scan");
  Serial.println(tca9548.scan());
}

void loop() {}
```
