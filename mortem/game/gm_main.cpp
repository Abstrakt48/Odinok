#include "gm_local.h"
#include "engine/sys.h"
#include "engine/mortemdef.h"
#include "common/cm_public.h"
#include "gm_funcs.h"

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