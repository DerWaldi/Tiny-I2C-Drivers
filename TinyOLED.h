/* TinyOLED v0.0.1

   Sebastian Murgul - www.sebastian-murgul.com - 29th June 2022
   
   CC BY 4.0
   Licensed under a Creative Commons Attribution 4.0 International license: 
   http://creativecommons.org/licenses/by/4.0/
*/

#ifndef TinyOLED_h
#define TinyOLED_h

#include <stdint.h>
#include <Arduino.h>
#include <avr/io.h>
#include <util/delay.h>

// OLED definitions
#define OLED_ADDR       0x3C                  // OLED write address
#define OLED_CMD_MODE   0x00                  // set command mode
#define OLED_DAT_MODE   0x40                  // set data mode
#define OLED_INIT_LEN   14                    // 12: no screen flip, 14: screen flip

class TinyOLED {

public:
  TinyOLED();
  void init(void);
  void clear(void);
  void shift(uint8_t ypos);
  void cursor(uint8_t xpos, uint8_t ypos);
  void printChar(char ch);
  void printStr(const char* p);

private:
  
};

#endif
