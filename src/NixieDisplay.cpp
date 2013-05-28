#include "NixieDisplay.h"
#include "operators.h"

const unsigned char NixieDisplay::map[10] = {0x04, 0x02, 0x0A, 0x0B, 0x03, 0x01, 0x09, 0x08, 0x00, 0x0C};

NixieDisplay::NixieDisplay() {
	expSS = new PCF8574(0x78);
	expMM = new PCF8574(0x70);
	expHH = new PCF8574(0x72);
}

void NixieDisplay::display(Time time) {
	expSS->write(map[time.s1] | (map[time.s10] << 4));
	expMM->write(map[time.m1] | (map[time.m10] << 4));
	expHH->write(map[time.h1] | (map[time.h10] << 4));
}
