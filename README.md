# TinyI2C-Drivers Library
This is a library for connecting different I2C peripherals to a tinyAVR 1-series microcontroller.

## Supported Peripherials
- SSD1306 based OLED I2C Display 128 x 32 pixels (https://www.az-delivery.de/en/products/0-91-zoll-i2c-oled-display)
- MCP4728 I2C Quad DAC (https://learn.adafruit.com/adafruit-mcp4728-i2c-quad-dac/overview)

## Getting Started

You need to install megaTinyCore in order to use this library on a tinyAVR 1-series microcontroller:
https://github.com/SpenceKonde/megaTinyCore/tree/master

<!-- START COMPATIBILITY TABLE -->

## Compatibility

MCU         |Tested Works|Doesn't Work|Not Tested|Notes
------------|:----------:|:----------:|:--------:|-----
ATtiny412   |      X     |            |          |
ATtiny414   |      X     |            |          |

<!-- END COMPATIBILITY TABLE -->

## Roadmap

- [X] SSD1306 OLED display text mode
- [X] MCP4728 quad DAC
- [ ] MCP4725 single DAC

## Credits
This library is built upon the TinyI2C library by technoblogy: https://github.com/technoblogy/tiny-i2c
