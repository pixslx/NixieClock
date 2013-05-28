#include "Time.h"

class PCF8583 {
	private:
		unsigned char address;
		void resumeCounting(void);
		void stopCounting(void);

	public:
		PCF8583(unsigned char);
		void setClockModeNotimerNoalarm(void);
		void setTime(Time*);
		Time* getTime(void);
};
