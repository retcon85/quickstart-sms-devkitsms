#include <stdint.h>
#include <stdbool.h>
#include "SMSlib.h"
#ifdef USEPSGLIB // Set USEPSGLIB := true in Makefile to build with PSGlib for music and sounds
#include "PSGlib.h"
#endif
#include "rom.h"
#include "assets.h"

static bool paused = false;

inline void game_init(void)
{
  // EXAMPLE
  SMS_displayOff();
  SMS_VDPturnOnFeature(VDPFEATURE_LEFTCOLBLANK);
  SMS_setNextTileatLoc(0);
  for (uint8_t line = 0; line < 28; line++)
  {
    for (uint8_t col = 0; col < 32; col++)
    {
      SMS_setTile(0);
    }
  }
  SMS_autoSetUpTextRenderer();
  SMS_printatXY(0, 0, "Hello, world!");
  SMS_displayOn();
  // END:EXAMPLE
}

inline void game_tick(void)
{
  // EXAMPLE
  static uint8_t scroll_x = 9, scroll_y = 184;
  static int8_t scroll_vx = 1, scroll_vy = -1;
  SMS_setBGScrollX(scroll_x);
  SMS_setBGScrollY(scroll_y + 40);
  if (scroll_x >= 152 || scroll_x < 8)
  {
    scroll_vx = -scroll_vx;
#ifdef USEPSGLIB
    PSGSFXPlay(bleep_psg, 0);
#endif
  }
  scroll_x += scroll_vx;
  if (scroll_y > 184)
  {
    scroll_vy = -scroll_vy;
#ifdef USEPSGLIB
    PSGSFXPlay(bloop_psg, 0);
#endif
  }
  scroll_y += scroll_vy;
  // END:EXAMPLE
}

inline void play_audio_frames(void)
{
#ifdef USEPSGLIB
  if (!paused)
  {
    SMS_saveROMBank();
    SMS_mapROMBank(MUSIC_BANK);
    PSGFrame();
    SMS_mapROMBank(SFX_BANK);
    PSGSFXFrame();
    SMS_restoreROMBank();
  }
#endif
}

void main(void)
{
  // do any one-off game initialization
  game_init();

  // main game loop, repeats indefinitely
  while (1)
  {
    // synchronize this loop to run every display frame (i.e. 50 or 60Hz)
    SMS_waitForVBlank();
    // if using PSGlib audio you must call PSGFrame, etc. at *regular* intervals, e.g. immediately after VBlank
    play_audio_frames();
    // if you are using sprites, you might want to update their positions once per frame for fluid motion
    SMS_copySpritestoSAT();

    // basic pause button handling
    if (SMS_queryPauseRequested())
    {
      paused = !paused;
      SMS_resetPauseRequest();
    }

    if (!paused)
    {
      // do game logic
      game_tick();
    }
  }
}
