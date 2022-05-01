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
