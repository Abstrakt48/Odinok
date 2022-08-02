#ifndef __ORDERDEF__
#define __ORDERDEF__

#include "tools/basetypes.h"

#define GAME "Order 1994"
#define GAME_RUS "Орден 1994" // for russian conversion and stuff
#define VERSION "0.04"
#define VERSION_NUM 0.04

#ifdef _WIN32
	#define DEVELOPER_MODE 999		// 0 = no, 1 = yes but on the machine running the game
									// 999 = yes but on developers machine
#else __linux__
	#define DEVELOPER_MODE 999
#endif

#if DEVELOPER_MODE == 999 // if is running on dev machine
	#ifdef _WIN32
		#define SRC_DIR		"" // directory for source code
	#else __linux__
		#define SRC_DIR		""
	#endif
#endif

#define GAME_DIR	"" // directory where the executable is
#define ASSET_DIR	"" // directory where all the assets are

#endif