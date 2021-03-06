#ifndef SevSeg_h
#define SevSeg_h
#include<stdint.h>

#ifndef MAXNUMDIGITS
#define MAXNUMDIGITS 2 
#endif

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

void start_SevSeg ();//function that runs at the beginning. this sets up the display
void refresh_SevSeg();
void setNewNum_SevSeg (uint8_t);//sets desired integer

#ifdef __cplusplus
}
#endif

#endif
