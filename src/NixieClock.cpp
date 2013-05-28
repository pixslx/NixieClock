#include "NixieClock.h"
#include "operators.h"

NixieClock::NixieClock(void) {
	time = new Time();

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
	(*time)++;
	if(!set) display->display(time);
}

void NixieClock::setKeyHandler(void) {
	if(!set) {
		set = 1;
		setPos = 1;		
		setChange = 0;
		delete tmpTime;
		tmpTime = time->clone();
	} else {
		if(setPos == 6) {
			set = 0;
			if(setChange) {
				delete time;
				time = tmpTime->clone();
			}
		}
		else setPos++;
	}
}

void NixieClock::upKeyHandler(void) {
	if(set) {
		setChange = 1;
		if(setPos == 6) tmpTime->incH10();
		else if(setPos == 5) tmpTime->incH1();
		else if(setPos == 4) tmpTime->incM10();
		else if(setPos == 3) tmpTime->incM1();
		else if(setPos == 2) tmpTime->incS10();
		else if(setPos == 1) tmpTime->incS1();
		display->display(tmpTime);
	}
}

