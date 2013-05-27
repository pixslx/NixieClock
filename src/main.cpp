#include "I2C.h"
#include "NixieClock.h"
#include "Key.h"
#include "operators.h"

NixieClock* clk;
Key<NixieClock>* setKey;
Key<NixieClock>* upKey;

ISR(INT1_vect) {
	clk->clock();
}

ISR(TIMER0_OVF_vect) {
	TCCR0 &= 0xF8;
	setKey->unblockKey();
	upKey->unblockKey();
}

int main() {
	I2C::init();

	clk = new NixieClock();
	setKey = new Key<NixieClock>(&DDRD, &PIND, 6, 1);
	upKey = new Key<NixieClock>(&DDRD, &PIND, 7, 0);

	upKey->onKeyHandler(clk, &NixieClock::upKeyHandler);
	setKey->onKeyHandler(clk, &NixieClock::setKeyHandler);

	while(1) {
		upKey->getState();
		setKey->getState();
	}
}
