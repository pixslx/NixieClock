#include <avr/io.h>
#include <avr/interrupt.h>
#include "NixieDisplay.h"
#include "Time.h"
#include "PCF8583.h"

class NixieClock {
	private:
		Time* time;
		Time* tmpTime;

		unsigned char set;
		unsigned char setPos;
		unsigned char setChange;

		NixieDisplay* display;

		PCF8583* i2cClock;

	public:
		NixieClock(void);
		void clock(void);
		void setKeyHandler(void);
		void upKeyHandler(void);
};
