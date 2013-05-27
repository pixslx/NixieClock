#include "Key.h"
#include "NixieClock.h"

template <typename keyHandlerClass>
Key<keyHandlerClass>::Key(volatile uint8_t* ddr, volatile uint8_t* port, unsigned char pin, unsigned char activePinState) {
	(*ddr) &= 0xFE << pin; 
	this->port = port;
	this->pin = pin;
	this->activePinState = activePinState;

	currentState = 0;
	previousState = 0;

	keyBlocked = 0;
}

template <typename keyHandlerClass>
void Key<keyHandlerClass>::getState(void) {
	if(!keyBlocked) {
		currentPinState = (*port) & (0x01 << pin);
		if((!activePinState && !currentPinState) || (activePinState && currentPinState)) currentState = 1;
		else currentState = 0;
		if(previousState == 0 && currentState == 1) keyPressed();
		previousState = currentState;
	}
}

template <typename keyHandlerClass>
void Key<keyHandlerClass>::onKeyHandler(keyHandlerClass* pInstance, void (keyHandlerClass::*pFunction)(void)) {
	pKeyHandlerInstance = pInstance;
	pKeyHandlerFunction = pFunction;
}

template <typename keyHandlerClass>
void Key<keyHandlerClass>::keyPressed(void) {
	blockKey();
	(pKeyHandlerInstance->*pKeyHandlerFunction)();
}

template <typename keyHandlerClass>
void Key<keyHandlerClass>::blockKey(void) {
	keyBlocked = 1;

	TCNT0 = 0;
	TCCR0 &= 0xF8;
	TCCR0 |= 0x05;
	sei();
	TIMSK |= (1 << TOIE0);	
}

template <typename keyHandlerClass>
void Key<keyHandlerClass>::unblockKey(void) {
	keyBlocked = 0;
}

template class Key<NixieClock>;

