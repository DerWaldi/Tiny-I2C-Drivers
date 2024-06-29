/* TinyOLED v0.0.1

   Sebastian Murgul - www.sebastian-murgul.com - 29th June 2022

   based on: https://github.com/adafruit/Adafruit_MCP4728/tree/master
   
   CC BY 4.0
   Licensed under a Creative Commons Attribution 4.0 International license: 
   http://creativecommons.org/licenses/by/4.0/
*/

#include "TinyMCP4728.h"
#include "TinyI2CMaster.h"

TinyMCP4728::TinyMCP4728() {
  
}

void TinyMCP4728::begin(uint8_t i2c_address) {
  TinyI2C.init();                          // initialize I2C first
  _addr = i2c_address;
}


void TinyMCP4728::setValue(MCP4728_channel_t channel, uint16_t new_value, MCP4728_vref_t new_vref,
    MCP4728_gain_t new_gain, MCP4728_pd_mode_t new_pd_mode, bool udac) {
  uint8_t output_buffer[3];

  // build the setter header/ "address"
  // 0 1 0 0 0 DAC1 DAC0 UDAC[A]
  uint8_t sequential_write_cmd = MCP4728_MULTI_IR_CMD;
  sequential_write_cmd |= (channel << 1);
  sequential_write_cmd |= udac;

  output_buffer[0] = sequential_write_cmd;
  // VREF PD1 PD0 Gx D11 D10 D9 D8 [A] D7 D6 D5 D4 D3 D2 D1 D0 [A]
  new_value |= (new_vref << 15);
  new_value |= (new_pd_mode << 13);
  new_value |= (new_gain << 12);

  output_buffer[1] = new_value >> 8;
  output_buffer[2] = new_value & 0xFF;

  TinyI2C.start(_addr, 0);                 // start transmission
  for (uint8_t i = 0; i < 3; i++) 
    TinyI2C.write(output_buffer[i]); 
  TinyI2C.stop();                          // stop transmission
}
