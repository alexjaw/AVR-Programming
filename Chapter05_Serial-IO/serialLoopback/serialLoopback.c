/*
A simple test of serial-port functionality.
Takes in a character at a time and sends it right back out,
 displaying the ASCII value on the LEDs.
*/

// ------- Preamble -------- //
#include <avr/io.h>
#include <util/delay.h>
#include "pinDefines.h"
#include "USART.h"

int main(void) {
  char serialCharacter;

  // -------- Inits --------- //
  LED_DDR = 0xff;                            /* set up LEDs for output */
  initUSART();
  printString("Hello World!\r\n");                          /* to test */

  // ------ Event loop ------ //
  while (1) {

    serialCharacter = receiveByte();
    transmitByte(serialCharacter);       //byte->char,   0->'0'
    printString("\r\n");
    printBinaryByte(serialCharacter);    //byte->binary, 0->00110000 (ascii) 
    printString("\r\n");
    printByte(serialCharacter);          //byte->dec,    0->048 (ascii)
    printString("\r\n");
    LED_PORT = serialCharacter;          /* display ascii/numeric value of character */

  }                                      /* End event loop */
  return 0;
}
