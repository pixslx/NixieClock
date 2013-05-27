#include <avr/io.h>

template <typename keyHandlerClass>
class Key {	
	private:
		volatile uint8_t* port;
		unsigned char pin;
		unsigned char currentPinState;
		unsigned char activePinState;
		unsigned char currentState;
		unsigned char previousState;
		unsigned char keyBlocked;

		keyHandlerClass* pKeyHandlerInstance;
		void (keyHandlerClass::*pKeyHandlerFunction)(void);

		void keyPressed(void);

	public:
		Key(volatile uint8_t*, volatile uint8_t*, unsigned char, unsigned char);
		void getState(void);
		void onKeyHandler(keyHandlerClass*, void (keyHandlerClass::*)(void));
		void blockKey(void);
		void unblockKey(void);
};
