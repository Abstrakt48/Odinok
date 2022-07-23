#include "game.h"
#include "mortemdef.h"
#include "public/string_t.h"
#include "engine/sys.h"

#include <stdlib.h>
#include <stdio.h>

int GM_MortemInit(void)
{
	// init code here
	return EXIT_SUCCESS;
};

void GM_MortemMain(void)
{
	string_t game = MAKE_STRING(GAME);
	string_t version = MAKE_STRING(VERSION);

	Sys_Printf("\n********** %s V%s *********\n", STRING(game), STRING(version));

	Sys_Exit(0);
};