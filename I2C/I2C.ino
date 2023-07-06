// IIC
#include <Wire.h>

TwoWire i2c1 = TwoWire(1);

void setup() {
  // put your setup code here, to run once:
  i2c1.begin(21, 22, 400000);
}

void loop() {
  // put your main code here, to run repeatedly:
  i2c1.beginTransmission(0x42);
  i2c1.write(140);
  i2c1.endTransmission();
  delay(100);
}
