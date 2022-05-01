# TCA9548

[tca9548 datasheet](https://cdn-shop.adafruit.com/datasheets/tca9548a.pdf) by adafruit


A2 A1 A0

L  L  L     112 (decimal), 70 (hexadecimal)

L  L  H     113 (decimal), 71 (hexadecimal)

L  H  L     114 (decimal), 72 (hexadecimal)

L  H  H     115 (decimal), 73 (hexadecimal)

H  L  L     116 (decimal), 74 (hexadecimal)

H  L  H     117 (decimal), 75 (hexadecimal)

H  H  L     118 (decimal), 76 (hexadecimal)

H  H  H     119 (decimal), 77 (hexadecimal)

# example

## Simple Scanner

```cpp
#define TCA9548_addr 0x70

#include "TCA9548.h"

CAM_TCA9548 tca9548;

void setup() {
  Serial.begin(9600);
  if (!tca9548.begin( TCA9548_addr )) {
    Serial.println("tca9548 not Found");
    while (1) {}
  }
  Serial.println(tca9548.scan());
}

void loop() {}
```

output

```
tca9548 Scan
Global (Ch. 0): 
 -  Address: 0x22
 -  Address: 0x70
Channel: 1
 -  Address: 0x27
Channel: 3
 -  Address: 0x75
Channel: 4
 -  Address: 0x27
Channel: 8
 -  Address: 0x20
```
