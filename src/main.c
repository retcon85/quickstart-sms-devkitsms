#include "SMSlib.h"
// #include "PSGlib.h"                uncomment if you want to use PSGlib
// #include "bank2.h"                 e.g. if using sverx's assets2banks utilitiy

SMS_EMBED_SEGA_ROM_HEADER(0, 0);  //  includes the TMR SEGA header in the ROM image

unsigned char paused = 0;

void main(void)
{
  // game initialization here
  
  // main game loop
  while (1)
  {
    SMS_waitForVBlank();
    if (!paused)
    {
      // PSGFrame();                   if using PSGlib you must call PSGFrame at *regular* intervals, e.g. here
    }
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
