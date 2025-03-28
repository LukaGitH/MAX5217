#include <Wire.h>
#define MAX5217  0x1F

void setup() {
  Wire.begin();

  // Optional: Reset or configure DAC if needed
  transmitToMAX5217(0x08, 0x00, 0x00);  // Example: Clear registers
}

void loop() {
  // Ramp up from 0 to 65535
  for (unsigned int val = 0; val <= 65535; val += 1000) {
    sendToDAC(val);
    delay(10);
  }

  // Ramp down from 65535 to 0
  for (unsigned int val = 65535; val >= 1000; val -= 1000) {
    sendToDAC(val);
    delay(10);
  }
}

void sendToDAC(unsigned int value_16bit) {
  byte dac_low = byte(value_16bit & 0x00FF);
  byte dac_high = byte((value_16bit & 0xFF00) >> 8);
  transmitToMAX5217(0x01, dac_high, dac_low);
}

void transmitToMAX5217(byte command, byte high_byte, byte low_byte) {
  Wire.beginTransmission(MAX5217);
  Wire.write(command);
  Wire.write(high_byte);
  Wire.write(low_byte);
  Wire.endTransmission();
}
