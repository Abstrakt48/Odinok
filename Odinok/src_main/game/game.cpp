#include "game.h"
#include "odindef.h"
#include "tools/string_t.h"
#include "system/system.h"

#include "tools/basetypes.h"

#include "renderer/render.h"
#include "tools/mathlib.h"

#include <stdlib.h>

int GM_OrderInit(void)
{
	// init code here
	return EXIT_SUCCESS;
};

void GM_OrderMain(void)
{
	Sys_Printf("\n********** %s V%s *********\n", GAME, VERSION);

	Sys_Exit(0);
};