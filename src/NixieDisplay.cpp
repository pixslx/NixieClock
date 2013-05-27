#include "NixieDisplay.h"
#include "operators.h"

const unsigned char NixieDisplay::map[10] = {0x04, 0x02, 0x0A, 0x0B, 0x03, 0x01, 0x09, 0x08, 0x00, 0x0C};

NixieDisplay::NixieDisplay() {
	expSS = new PCF8574(0x78);
	expMM = new PCF8574(0x70);
	expHH = new PCF8574(0x72);
}

void NixieDisplay::display(unsigned char hh, unsigned char mm, unsigned char ss) {
	expSS->write(map[ss & 0x0F] | (map[(ss & 0xF0) >> 4] << 4));
	expMM->write(map[mm & 0x0F] | (map[(mm & 0xF0) >> 4] << 4));
	expHH->write(map[hh & 0x0F] | (map[(hh & 0xF0) >> 4] << 4));
}
