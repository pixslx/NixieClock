#include <avr/io.h>
#include <avr/interrupt.h>
#include "NixieDisplay.h"
#include "Time.h"

class NixieClock {
	private:
		Time time;

		unsigned char set;
		unsigned char setPos;

		NixieDisplay* display;

	public:
		NixieClock(void);
		void clock(void);
		void setKeyHandler(void);
		void upKeyHandler(void);
};
