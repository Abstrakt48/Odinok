#include "odinok.h"
#include "odindef.h"
#include "assetlist.h"

#include "tools/string_t.h"
#include "system/system.h"

#include "renderer/render.h"

#include "tools/basetypes.h"

#include <stdlib.h>

Image newImage;

void ImageTest()
{
	newImage.R_CreateImage(textureAssets[4], Vector2D(360,240),0,otrue);
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
		Sys_Printf("Image info: %s, %f %f\n", newImage.imgName, newImage.dimensions.x, newImage.dimensions.y);
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