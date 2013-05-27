/* define CPU frequency in Mhz here if not defined in Makefile */
#ifndef F_CPU
#define F_CPU 16000000UL
#endif

/* I2C clock in Hz */
#define SCL_CLOCK  100000L

class I2C {
	public:
		/*************************************************************************
		 Initialization of the I2C bus interface. Need to be called only once
		*************************************************************************/
		static void init(void);

		/*************************************************************************	
		  Issues a start condition and sends address and transfer direction.
		  return 0 = device accessible, 1= failed to access device
		*************************************************************************/
		static unsigned char start(unsigned char);

		/*************************************************************************
		 Issues a start condition and sends address and transfer direction.
		 If device is busy, use ack polling to wait until device is ready
		 
		 Input:   address and transfer direction of I2C device
		*************************************************************************/
		static void start_wait(unsigned char);

		/*************************************************************************
		 Issues a repeated start condition and sends address and transfer direction 

		 Input:   address and transfer direction of I2C device
		 
		 Return:  0 device accessible
			  1 failed to access device
		*************************************************************************/
		static unsigned char rep_start(unsigned char);

		/*************************************************************************
		 Terminates the data transfer and releases the I2C bus
		*************************************************************************/
		static void stop(void);

		/*************************************************************************
		  Send one byte to I2C device
		  
		  Input:    byte to be transfered
		  Return:   0 write successful 
			    1 write failed
		*************************************************************************/
		static unsigned char write( unsigned char );

		/*************************************************************************
		 Read one byte from the I2C device, request more data from device 
		 
		 Return:  byte read from I2C device
		*************************************************************************/
		static unsigned char readAck(void);

		/*************************************************************************
		 Read one byte from the I2C device, read is followed by a stop condition 
		 
		 Return:  byte read from I2C device
		*************************************************************************/
		static unsigned char readNak(void);

};
