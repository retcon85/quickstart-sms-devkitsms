#include <stdint.h>
#include <stdbool.h>
#include "SMSlib.h"
#ifdef USEPSGLIB // Set USEPSGLIB := true in Makefile to build with PSGlib for music and sounds
#include "PSGlib.h"
#endif
#include "rom.h"
#include "assets.h"

bool paused = false;

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
      PSGSFXFrame();
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
