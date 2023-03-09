#include "pico/stdlib.h"
#include "pins.h"
#include "main.h"


#ifdef STOCK_ROM
#include "roms/stock.c"
#endif


int main() {
  pinSetup();

  unsigned address = 0;

  while (true) {
    if (!gpio_get(CE)) {
        address = readAddress();
        outputByte(address);
      }
  }
}


unsigned readAddress()
{
  unsigned address_pins[] = {
    A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12,
  };
	unsigned value = 0;
	for (unsigned i = 0; i < 13; ++i)
		value = value << 1 | gpio_get(address_pins[i]);
	return value;
}

void outputByte(unsigned address) {
  unsigned data_pins[] = {
    D0, D1, D2, D3, D4, D5, D6, D7,
  };
  unsigned byte = stock_rom[address];
  for (unsigned i = 8 - 1; i < 8; --i) {
		gpio_put(data_pins[i], byte & 1);
		byte = byte >> 1;
	}
}

void pinSetup() {
  //Initialise pins
  for (unsigned i=A0; i<=CE; ++i) {
    gpio_init(i);
  }

  //Setup Address Lines
  for (unsigned a=A0; a<=A12; ++a) {
    gpio_set_dir(a, GPIO_IN);
  }

  //Setup Data Lines
  for (unsigned d=D0; d<=D7; ++d) {
    gpio_set_dir(d, GPIO_OUT);
  }

  //Chip Enable / Output Enable
  gpio_set_dir(CE, GPIO_IN);
}

