#include "pico/stdlib.h"
#include "pins.h"


#ifdef STOCK_ROM
#include "roms/stock.c"
#endif


int main() {
  pinSetup();

  long int address = 0x0000;

  while (true) {
    if (!gpio_get(CE)) {
        address = readAddress();
        outputByte(address);
      }
  }
}

int readAddress() {
  char address[14] = {
    gpio_get(A0),
    gpio_get(A1),
    gpio_get(A2),
    gpio_get(A3),
    gpio_get(A4),
    gpio_get(A5),
    gpio_get(A6),
    gpio_get(A7),
    gpio_get(A8),
    gpio_get(A9),
    gpio_get(A10),
    gpio_get(A11),
    gpio_get(A12)
  };
  long int ret = strtol(address, NULL, 2);
  return ret;
}

void outputByte(long int address) {
  byte = stock_rom[address];

}

void pinSetup() {
  //Initialise pins
  for (i=A0; i<=CE; ++i) {
    gpio_init(i);
  }

  //Setup Address Lines
  for (a=A0; a<=A12; ++a) {
    gpio_set_dir(a, GPIO_IN);
  }

  //Setup Data Lines
  for (d=D0; d<=D7; ++d) {
    gpio_set_dir(d, GPIO_OUT);
  }

  //Chip Enable / Output Enable
  gpio_set_dir(CE, GPIO_IN);
}

