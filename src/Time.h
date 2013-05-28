#ifndef TIME_H
#define TIME_H

class Time {
	private:
		void incrementTime(void);

	public:
		unsigned char h1;
		unsigned char h10;
		unsigned char m1;
		unsigned char m10;
		unsigned char s1;
		unsigned char s10;
		
		Time(void);

		Time& operator++();
		Time& operator++(int);

		Time* clone(void);

		void incH1(void);
		void incH10(void);
		void incM1(void);
		void incM10(void);
		void incS1(void);
		void incS10(void);
};

#endif
