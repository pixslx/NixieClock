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
}

int main() {

	I2C::init();

	clk = new NixieClock();
	setKey = new Key<NixieClock>(&PORTD, 6);
	upKey = new Key<NixieClock>(&PORTD, 7);

	setKey->onKeyHandler(&(*clk), &NixieClock::setKeyHandler);
	while(1) {
	}
}
