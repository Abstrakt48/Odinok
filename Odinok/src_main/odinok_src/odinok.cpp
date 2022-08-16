#include "odinok.h"
#include "odindef.h"
#include "assetlist.h"

#include "tools/string_t.h"
#include "system/system.h"

#include "renderer/render.h"

#include "tools/basetypes.h"

#include <stdlib.h>

void ImageTest()
{
	Odinok::testImage.R_CreateImage(textureAssets[0], Vector2D(64,64), 0, ofalse);
};

// odinok code
void Odinok::onCreate()
{
	Sys_Printf("\n********** %s V%s *********\n", GAME, VERSION);

	ImageTest();
}

void Odinok::onUpdate()
{
	while (isRunning)
	{
		Sys_Printf("Image info: %s, %f %f\n", testImage.imgName, testImage.dimensions.x, testImage.dimensions.y);
		Sys_Printf("Pausing for 3 seconds...\n");
		Sys_Sleep(uFullSecond * 3);
	
		// will cause while loop to end and game to quit
		isRunning = false;
	}
}

void Odinok::onQuit()
{
	// Shutdown all subsystems
	Sys_Printf("Exiting %s V%s\n", GAME, VERSION);
}