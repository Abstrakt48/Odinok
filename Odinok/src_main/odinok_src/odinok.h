#ifndef __ODINOK__
#define __ODINOK__

#include "game/game.h"

#include "renderer/render.h"

class Odinok : public Game
{
public:
	void onCreate() override;
	void onUpdate() override;
	void onQuit() override;
protected:
	int fpsLimiter = 60;
public:
	// extra external game defs
	static Image testImage;
};

#endif