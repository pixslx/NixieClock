#include "I2C.h"
#include "PCF8574.h"

PCF8574::PCF8574(unsigned char address) {
	this->address = address;
}

void PCF8574::write(unsigned char data) {
	I2C::start(address);
	I2C::write(data);
	I2C::stop();
}

unsigned char PCF8574::read(void) {
	unsigned char return_value;

	I2C::start(address);
	return_value = I2C::readNak();
	I2C::stop();
	
	return return_value;
}
