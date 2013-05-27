class PCF8574 {
	private:
		unsigned char address;
	public:
		// Constructor
		// Input - device address
		PCF8574(unsigned char);

		// Write data to output port
		// Input - data to be written
		void write(unsigned char);

		// Read data from port
		// Output - data read from port
		unsigned char read(void);
};


