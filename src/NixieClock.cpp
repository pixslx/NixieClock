#include "NixieClock.h"
#include "operators.h"

NixieClock::NixieClock(void) {
	display = new NixieDisplay();	
	display->display(time);

	set = 0;

	DDRD = 0<<PD3;
	PORTD = 1<<PD3;
	GICR = 1<<INT1;
	MCUCR = 1<<ISC11 | 0<<ISC10;
	SREG |= 0x80;
	sei();
}

void NixieClock::clock(void) {
	if(!set) {
		time++;
		display->display(time);
	}
}

void NixieClock::setKeyHandler(void) {
	if(!set) {
		set = 1;
		setPos = 1;
	} else {
		if(setPos == 6) set = 0;
		else setPos++;
	}
}

void NixieClock::upKeyHandler(void) {
	if(set) {
		if(setPos == 1) time.incH10();
		else if(setPos == 2) time.incH1();
		else if(setPos == 3) time.incM10();
		else if(setPos == 4) time.incM1();
		else if(setPos == 5) time.incS10();
		else if(setPos == 6) time.incS1();
		display->display(time);
	}
}

