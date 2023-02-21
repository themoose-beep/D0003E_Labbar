#include <avr/io.h>
#include "TinyTimber.h"

typedef struct controller {
    Object super;
    bool active;
} controller;


void writeChar(char ch, int pos) {
	// Chars 0-9 + a blank
	
	//uint16_t sccMap[] =
	
	uint8_t mask;
	
	uint8_t *writePos = &LCDDR0;
	
	
	if (pos > 5 || pos < 0) {
		return;
	}
	
	
	// Convert from char representation to integer
	uint8_t intCh = ch - '0';
	
	if (intCh > 9 || intCh < 0) {
		intCh = 10;
	};
	
	// Decide which reg
	writePos += pos >> 1;
	
	// Decide of upper or lower nibble of reg
	if (pos % 2 == 0) {
		mask = 0x0f;
	}
	else {
		mask = 0xf0;
	}
	
	uint16_t sccChar = sccMap[intCh];
	
	// Repeat for all four nibbles
	for (int i = 0; i < 4; i++) {
		// Get relevant nibble
		uint8_t writeCh = (sccChar >> i*4) & 0xf;
		
		// Reset nibble to write, if i = 0 we do not want to overwrite the middle bits
		if (i == 0) {
			*writePos = (*writePos & ~mask) | (*writePos & 0x66);
			} else {
			*writePos = *writePos & ~mask;
		}
		
		
		// Duplicate nibble to upper and mask to write to upper or lower nibble of reg
		*writePos = ((writeCh | (writeCh << 4)) & mask) | *writePos;
		
		// Next nibble
		writePos += 5;

	}
	return;
	
	
}

void printAt(long num, int pos) {
    int pp = pos;
    writeChar( (num % 100) / 10 + '0', pp);
	for(volatile int i = 0; i < 1000; i++);
    pp++;
    writeChar( num % 10 + '0', pp);

}

void switchActive (controller *self) {
    self->active = !self->active;
    //activate other lcd part

}