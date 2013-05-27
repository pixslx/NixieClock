#include <avr/io.h>
#include <avr/interrupt.h>
#include "NixieDisplay.h"

class NixieClock {
	private:
		unsigned char ss;
		unsigned char mm;
		unsigned char hh;

		unsigned char set;
		unsigned char setPos;

		NixieDisplay* display;

	public:
		NixieClock(void);
		void clock(void);
		void setKeyHandler(void);
		void upKeyHandler(void);
};
