#ifndef _PULSESENDER_
#define _PULSESENDER_

#include "TinyTimber.h"
#include <stdint.h>
#include "Gui.h"

typedef struct {
    Object super;
} PulseSender;

#define initPulseSender() {initObject()}

void sendPulse(PulseSender *self, uint8_t pin);

void resetPin(PulseSender *self, uint8_t pin);

#endif