F_CPU = 16000000UL
SCL_CLOCK = 100000L

MCU = atmega8
FORMAT = ihex
TARGET = nixie

AVRDUDE_PROGRAMMER = ponyser
AVRDUDE_PORT = /dev/ttyS0
AVRDUDE_WRITE_FLASH = -U flash:w:$(BIN_DIR)/$(TARGET).hex:i
AVRDUDE_FLAGS = -p $(MCU) -P $(AVRDUDE_PORT) -c $(AVRDUDE_PROGRAMMER)

CC = avr-gcc
OBJCOPY = avr-objcopy
AVRDUDE = avrdude

SRC_DIR = src
BIN_DIR = bin
SRC_C = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(patsubst $(SRC_DIR)/%,$(BIN_DIR)/%,$(SRC_C:.cpp=.o))

all: load clean

clean:
	rm -f $(BIN_DIR)/*

load: build
	$(AVRDUDE) $(AVRDUDE_FLAGS) $(AVRDUDE_WRITE_FLASH) $(AVRDUDE_WRITE_EEPROM)

build: link
	$(OBJCOPY) -O $(FORMAT) $(BIN_DIR)/$(TARGET).elf $(BIN_DIR)/$(TARGET).hex

link: $(OBJ)
	$(CC) -g -mmcu=$(MCU) -o $(BIN_DIR)/$(TARGET).elf $^

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) -g -Os -mmcu=$(MCU) -c -o $@ $<

