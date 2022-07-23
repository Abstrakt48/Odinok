#include "game.h"
#include "orderdef.h"
#include "public/string_t.h"
#include "engine/sys.h"

#include <stdlib.h>
#include <stdio.h>

int GM_OrderInit(void)
{
	// init code here
	return EXIT_SUCCESS;
};

void GM_OrderMain(void)
{
	string_t game = MAKE_STRING(GAME);
	string_t version = MAKE_STRING(VERSION);

	Sys_Printf("\n********** %s V%s *********\n", STRING(game), STRING(version));

	Sys_Exit(0);
};