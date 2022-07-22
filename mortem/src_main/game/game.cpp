#include "game.h"
#include "engine/sys.h"
#include "mortemdef.h"
#include "common/types.h"

#include <stdlib.h>

int GM_MortemInit(void)
{
	// init code here
	return Success;
};

void GM_MortemMain(void)
{
	Sys_Printf("\n******************** %s %s ********************\n", GAME, VERSION);
	Sys_Exit(et_normal);
};