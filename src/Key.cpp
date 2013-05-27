#include "Key.h"
#include "NixieClock.h"

template <typename keyHandlerClass>
Key<keyHandlerClass>::Key(volatile uint8_t* port, unsigned char pin) {
	this->port = port;
	this->pin = pin;
}

template <typename keyHandlerClass>
void Key<keyHandlerClass>::getState(void) {
	currentState = (*port) & (0x01 << pin);
	(pKeyHandlerInstance->*pKeyHandlerFunction)();

}

template <typename keyHandlerClass>
void Key<keyHandlerClass>::onKeyHandler(keyHandlerClass* pInstance, void (keyHandlerClass::*pFunction)(void)) {
	pKeyHandlerInstance = pInstance;
	pKeyHandlerFunction = pFunction;
}

template class Key<NixieClock>;

