#ifndef GUI_H_
#define GUI_H_

#include "TinyTimber.h"
#include <stdbool.h>


typedef struct GUI {
  Object super;
  bool active;
} GUI;

#define initGUI() \
		{ initObject(), 0}

void InitLCD(GUI *self);

void switchActive(GUI *self); 

#endif