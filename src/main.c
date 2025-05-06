#include <stdint.h>
#include <stdbool.h>
#include "SMSlib.h"
#include "rom.h"

void main(void)
{
  while (1)
  {
    SMS_waitForVBlank();
  }
}
