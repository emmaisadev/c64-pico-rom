#include "pico/stdlib.h"

#ifdef STOCK_ROM
#include "roms/stock.c"
#endif

// Pin definitions
// Left Half ROM
const uint A7 = 0;
const uint A6 = 1;
const uint A5 = 2;
const uint A4 = 3;
const uint A3 = 4;
const uint A2 = 5;
const uint A1 = 6;
const uint A0 = 7;
const uint D0 = 8;
const uint D1 = 9;
const uint D2 = 10;

//Right Half ROM
const uint D3 = 11;
const uint D4 = 12;
const uint D5 = 13;
const uint D6 = 14;
const uint D7 = 15;
const uint A11 = 16;
const uint A10 = 17;
const uint CE = 18;
const uint A12 = 19;
const uint A9 = 20;
const uint A8 = 21;

//Misc pins


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
  gpio_init(A0);
  gpio_init(A1);
  gpio_init(A2);
  gpio_init(A3);
  gpio_init(A4);
  gpio_init(A5);
  gpio_init(A6);
  gpio_init(A7);
  gpio_init(A8);
  gpio_init(A9);
  gpio_init(A10);
  gpio_init(A11);
  gpio_init(A12);
  gpio_init(D0);
  gpio_init(D1);
  gpio_init(D2);
  gpio_init(D3);
  gpio_init(D4);
  gpio_init(D5);
  gpio_init(D6);
  gpio_init(D7);
  gpio_init(CE);

  //Setup Address Lines
  gpio_set_dir(A0, GPIO_IN);
  gpio_set_dir(A1, GPIO_IN);
  gpio_set_dir(A2, GPIO_IN);
  gpio_set_dir(A3, GPIO_IN);
  gpio_set_dir(A4, GPIO_IN);
  gpio_set_dir(A5, GPIO_IN);
  gpio_set_dir(A6, GPIO_IN);
  gpio_set_dir(A7, GPIO_IN);
  gpio_set_dir(A8, GPIO_IN);
  gpio_set_dir(A9, GPIO_IN);
  gpio_set_dir(A10, GPIO_IN);
  gpio_set_dir(A11, GPIO_IN);
  gpio_set_dir(A12, GPIO_IN);

  //Setup Data Lines
  gpio_set_dir(D0, GPIO_OUT);
  gpio_set_dir(D1, GPIO_OUT);
  gpio_set_dir(D2, GPIO_OUT);
  gpio_set_dir(D3, GPIO_OUT);
  gpio_set_dir(D4, GPIO_OUT);
  gpio_set_dir(D5, GPIO_OUT);
  gpio_set_dir(D6, GPIO_OUT);
  gpio_set_dir(D7, GPIO_OUT);

  //Chip Enable / Output Enable
  gpio_set_dir(CE, GPIO_IN);
}

