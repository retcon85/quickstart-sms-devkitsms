#include <stdint.h>
#include "SMSlib.h"
#ifdef USEPSGLIB // Set USEPSGLIB := true in Makefile to build with PSGlib for music and sounds
#include "PSGlib.h"
#endif
#include "assets.generated.h" // e.g. if using sverx's assets2banks utilitiy

SMS_EMBED_SEGA_ROM_HEADER(0, 0); //  includes the TMR SEGA header in the ROM image

uint8_t paused = 0;

void main(void)
{
  // game initialization here

  // main game loop
  while (1)
  {
    SMS_waitForVBlank();

#ifdef USEPSGLIB
    if (!paused)
    {
      PSGFrame(); // if using PSGlib you must call PSGFrame at *regular* intervals, e.g. here
    }
#endif
    SMS_copySpritestoSAT();
    if (SMS_queryPauseRequested())
    {
      paused = !paused;
      SMS_resetPauseRequest();
    }

    if (!paused)
    {
      // game logic here
    }
  }
}
