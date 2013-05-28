#include "PCF8583.h"
#include "I2C.h"

PCF8583::PCF8583(unsigned char address) {
	this->address = address;
}

void PCF8583::stopCounting(void ) {
	I2C::start(address + I2C::WRITE_BIT);
	I2C::write(0x00);
	I2C::write(0x80);
	I2C::stop();
}

void PCF8583::resumeCounting(void ) {
	I2C::start(address + I2C::WRITE_BIT);
	I2C::write(0x00);
	I2C::write(0x00);
	I2C::stop();
}

void PCF8583::setClockModeNotimerNoalarm(void ) {
	I2C::start(address + I2C::WRITE_BIT);
	I2C::write(0x00);
	I2C::write(0x00);
	I2C::stop();
}

void PCF8583::setTime(Time* time) {
	stopCounting();

	// write hundredth of seconds
	I2C::start(address + I2C::WRITE_BIT);
	I2C::write(0x01);
	I2C::write(0x00);
	I2C::stop();

	// write seconds
	I2C::start(address + I2C::WRITE_BIT);
	I2C::write(0x02);
	I2C::write((time->s10 << 4) | time->s1);
	I2C::stop();

	// write seconds
	I2C::start(address + I2C::WRITE_BIT);
	I2C::write(0x03);
	I2C::write((time->m10 << 4) | time->m1);
	I2C::stop();

	// write hours
	I2C::start(address + I2C::WRITE_BIT);
	I2C::write(0x04);
	I2C::write((time->h10 << 4) | time->h1);
	I2C::stop();

	resumeCounting();

}

Time* PCF8583::getTime(void) {
	Time* time = new Time();
	unsigned char tmp;

	I2C::start(address + I2C::WRITE_BIT);
	I2C::write(0x02);
	I2C::rep_start(address + I2C::READ_BIT);

	tmp = I2C::readAck();
	time->s1 = tmp & 0x0F;
	time->s10 = (tmp & 0xF0) >> 4;

	tmp = I2C::readAck();
	time->m1 = tmp & 0x0F;
	time->m10 = (tmp & 0xF0) >> 4;

	tmp = I2C::readNak();
	time->h1 = tmp & 0x0F;
	time->h10 = (tmp & 0x30) >> 4;

	I2C::stop();

	return time;
}

