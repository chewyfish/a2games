#ifndef __SOUND_C__
#define __SOUND_C__ 1

#include "common.h"

#define CLICK STROBE(0xc030)

// Emit tone utilizing given sound parameters
//
////////////////////////////////////////////////////////////////////////////////
void tone(unsigned char period, unsigned char dur, signed char mod)
{
  unsigned short i;
  while (dur--)
  {
    for (i=0; i<period; i++) ;
    CLICK;
    period += mod;
  }
}

#endif // __SOUND_C__
