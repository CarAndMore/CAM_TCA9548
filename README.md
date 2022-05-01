# TCA9548

[tca9548 datasheet](https://cdn-shop.adafruit.com/datasheets/tca9548a.pdf) by adafruit


![tca9548](/img/tca9548.svg)

 <table>
  <tr>
    <th>A2</th><th>A1</th><th>A0</th><th>decimal</th><th>hexadecimal</th>    
  </tr>
  <tr>
    <td>L</td><td>L</td><td>L</td> <td>112</td> <td>70</td>    
  </tr>
  <tr>
    <td>L</td><td>L</td><td>H</td> <td>113</td> <td>71</td>    
  </tr>
  <tr>
    <td>L</td><td>H</td><td>L</td> <td>114</td> <td>72</td>    
  </tr>
  <tr>
    <td>L</td><td>H</td><td>H</td> <td>115</td> <td>73</td>    
  </tr>
  <tr>
    <td>H</td><td>L</td><td>L</td> <td>116</td> <td>74</td>    
  </tr>
  <tr>
    <td>H</td><td>L</td><td>H</td> <td>117</td> <td>75</td>    
  </tr>
  <tr>
    <td>H</td><td>H</td><td>L</td> <td>118</td> <td>76</td>    
  </tr>
  <tr>
    <td>H</td><td>H</td><td>H</td> <td>119</td> <td>77</td>    
  </tr>
</table> 


# example

## DEMO 1: Simple Scanner

```cpp
#define TCA9548_addr 0x70

#include <cam_tca9548.h>

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

## DEMO 2:

```cpp

#define PCA8574_addr      0x27 // LCD 1 + 2
#define TCA9548_addr      0x70 // I2C Multiplexer
#define HT16K33_addr      0x75 // LED Matrix / 7 Seg. anzeige

#define Ch_LCD_1          B00000001 // TCA9548 Channel 1
#define Ch_HT16K33Clock   B00000100 // TCA9548 Channel 3
#define Ch_LCD_2          B00001000 // TCA9548 Channel 4

#include <cam_tca9548.h>
#include <LiquidCrystal_I2C.h>
// #include "SEVEN_SEG.h"

CAM_TCA9548 tca9548;
// SEVEN_SEG sevenSeg;

LiquidCrystal_I2C lcd(PCA8574_addr, 20, 4);

void setup() {
  
  Serial.begin(9600);
  if (!tca9548.begin( TCA9548_addr )) {
    Serial.println("tca9548 not Found");
    while (1) {}
  }
  
  Serial.println(tca9548.scan());
  
  if (tca9548.test_device(Ch_HT16K33Clock, HT16K33_addr)) {
    // sevenSeg.begin( HT16K33_addr );
  }

  if (tca9548.test_device(Ch_LCD_1, PCA8574_addr)) {
    lcd.init();
    lcd.backlight();
    lcd.clear();
    lcd.setCursor(15, 1);
    lcd.print("LCD 1");
  }
  if (tca9548.test_device(Ch_LCD_2, PCA8574_addr)) {
    lcd.init();
    lcd.clear();
    lcd.backlight();
    lcd.setCursor(15, 1);
    lcd.print("LCD 2");
  }
}

void loop() {
  for (uint16_t Count = 0; Count < 10000; Count++) {
    if (tca9548.test_device(Ch_HT16K33Clock, HT16K33_addr)) {
      // sevenSeg.print_int(Count);
    }
    if (tca9548.test_device(Ch_LCD_1, PCA8574_addr)) {
      lcd.setCursor(5, 3);
      lcd.print("     ");
      lcd.setCursor(5, 3);
      lcd.print(Count);
    }
    if (tca9548.test_device(Ch_LCD_2, PCA8574_addr)) {
      lcd.setCursor(5, 3);
      lcd.print("     ");
      lcd.setCursor(5, 2);
      lcd.print(Count);
    }
    delay(1000);
  }
}
```
