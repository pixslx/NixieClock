#include <avr/io.h>

template <typename keyHandlerClass>
class Key {	
	private:
		volatile uint8_t* port;
		unsigned char pin;
		unsigned char currentState;

		keyHandlerClass* pKeyHandlerInstance;
		void (keyHandlerClass::*pKeyHandlerFunction)(void);

	public:
		Key(volatile uint8_t*, unsigned char);
		void getState(void);
		void onKeyHandler(keyHandlerClass*, void (keyHandlerClass::*)(void));
};
