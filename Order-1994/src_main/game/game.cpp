#include "game.h"
#include "orderdef.h"
#include "public/string_t.h"
#include "engine/sys.h"

#include "tools/basetypes.h"

#include "renderer/r_local.h"

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