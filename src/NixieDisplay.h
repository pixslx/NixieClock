#include "PCF8574.h"

class NixieDisplay {
	private:
		PCF8574* expHH;
		PCF8574* expMM;
		PCF8574* expSS;
		static const unsigned char map[10];

	public:
		NixieDisplay(void);
		void display(unsigned char, unsigned char, unsigned char);
};
