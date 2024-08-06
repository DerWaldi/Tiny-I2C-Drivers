#include <Tiny-I2C-Drivers.h>

// messages to print on OLED
const char Message1[] = "HELLO WORLD !";
const char Message2[] = "ATTINY414 GOES OLED !";
const char Message3[] = "THE QUICK BROWN FOX";
const char Message4[] = "JUMPS OVER THE LAZY";
const char Message5[] = "DOG  - (0123456789)";

TinyOLED oled;

void setup()
{
  oled.init();  // initialize the OLED
  oled.clear(); // clear screen
}

void loop()
{
  // print messages
  oled.clear();            // clear screen
  oled.cursor(20, 0);      // set cursor position
  oled.printStr(Message1); // print message 1
  delay(1000);             // wait a second
  oled.cursor(0, 2);       // set cursor position
  oled.printStr(Message2); // print message 2
  delay(4000);             // wait 4 seconds
  oled.clear();
  oled.cursor(0, 0);       // set cursor next line
  oled.printStr(Message3); // print message 3
  oled.cursor(0, 1);       // set cursor next line
  oled.printStr(Message4); // print message 4
  oled.cursor(0, 2);       // set cursor next line
  oled.printStr(Message5); // print message 5
  delay(4000);             // wait 4 seconds

  // print all characters
  oled.cursor(0, 0); // set cursor at upper left corner
  for (uint8_t i = 32; i < 64 + 32; i++)
    oled.printChar(i); // print all characters
  delay(3000);         // wait 3 seconds

  // scroll out the text
  for (uint8_t i = 0; i < 32; i++)
  {                // shift 32 pixels upwards
    oled.shift(i); // set vertical shift value
    delay(100);    // delay a bit
  }
}
