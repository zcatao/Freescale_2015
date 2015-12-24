
#include "Include.h"


void SPR_init(void) 
{
      SPR_dir = 1;
      SPR = 1;
      SPR = 0;
      Delay_ms(500);
      SPR = 1;
	  Delay_ms(500);
}