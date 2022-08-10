#ifndef __ODINOK__
#define __ODINOK__

#include "game/game.h"

class Odinok : public Game
{
public:
	void onCreate() override;
	void onUpdate() override;
	void onQuit() override;
protected:
	int fpsLimiter = 60;
};

#endif