# MAX5217 Arduino Example

This is a simple Arduino sketch to interface with the **MAX5217** 16-bit DAC (Digital-to-Analog Converter) over I2C using the Wire library.

## 🔧 Hardware Required

- Arduino (Uno, Mega, Nano, etc.)
- MAX5217 DAC module (I2C address: `0x1F`)

## 🧠 How It Works

This sketch initializes the MAX5217 and sends a smooth ramp-up and ramp-down waveform by gradually increasing and decreasing a 16-bit value via I2C.

### I2C Command Breakdown:

- **Register `0x01`** is used to update the DAC output.
- The 16-bit value is split into high and low bytes before being transmitted.

### Example Output Sequence:
- Ramps DAC output up from 0 to 65535 in steps
- Then ramps back down from 65535 to 0
- Repeats continuously
