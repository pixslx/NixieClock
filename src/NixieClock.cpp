#include "NixieClock.h"
#include "operators.h"

NixieClock::NixieClock(void) {
	display = new NixieDisplay();
	hh = 0x00; mm = 0x00; ss = 0x00;
	display->display(0x00,0x00,0x00);

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
		ss++;
	
		if((ss & 0x0F) == 0x0A) ss += 6;
		if(ss == 0x60) {
			ss = 0x00;
			mm++;
		}

		if((mm & 0x0F) == 0x0A) mm += 6;
		if(mm == 0x60) {
			mm = 0x00;
			hh++;
		}

		if((hh & 0x0F) == 0x0A) hh += 6;
		if(hh == 0x24) {
			hh = 0x00;
		}

		display->display(hh,mm,ss);
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
		clock();
	}
}

