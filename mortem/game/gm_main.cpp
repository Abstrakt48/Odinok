#include "gm_local.h"
#include "engine/sys.h"
#include "mortemdef.h"
#include "types.h"

#include <stdlib.h>

int GM_MortemInit(void)
{
	isGameInit = mTrue;
	return EXIT_SUCCESS;
};

void GM_MortemMain(void)
{
	Sys_Printf("\n******************** %s %d.%d ********************\n", GAME, VERSION, VERSION_SMALL);
};