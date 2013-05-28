#include "Time.h"
#include "operators.h"

Time::Time(void) : h1(0),h10(0),m1(0),m10(0),s1(0),s10(0) {}

void Time::incrementTime(void) {
	s1++;
	if(s1 == 10) {
		s1 = 0;
		s10++;
		if(s10 == 6) {
			s10 = 0;
			m1++;
			if(m1 == 10) {
				m1 = 0;
				m10++;
				if(m10 == 6) {
					m10 = 0;
					h1++;
					if(h10 == 2 && h1 == 4) {
						h10 = 0;
						h1 = 0;
					} else if(h1 == 10) {
						h1 = 0;
						h10++;
					}
				}
			}
		}
	}
}

Time& Time::operator++() {
	incrementTime();
	return *this;
}

Time& Time::operator++(int unused) {
	incrementTime();
	return *this;
}

Time* Time::clone(void) {
	Time* clone = new Time();
	clone->h1 = h1;
	clone->h10 = h10;
	clone->m1 = m1;
	clone->m10 = m10;
	clone->s1 = s1;
	clone->s10 = s10;
	return clone;
}

void Time::incH1(void) {
	if(h10 == 2 && h1 == 3) h1 = 0;
	else if(h1 == 9) h1 = 0;
	else h1++;
}
void Time::incH10(void) {
	if(h10 == 1 && h1 > 3) h10 = 0;
	else if(h10 == 2) h10 = 0;
	else h10++;
}

void Time::incM1(void) {
	if(m1 == 9) m1 = 0;
	else m1++;
}
void Time::incM10(void) {
	if(m10 == 5) m10 = 0;
	else m10++;
}

void Time::incS1(void) {
	if(s1 == 9) s1 = 0;
	else s1++;
}
void Time::incS10(void) {
	if(s10 == 5) s10 = 0;
	else s10++;
}
