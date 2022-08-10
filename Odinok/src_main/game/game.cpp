#include "game.h"
#include "system/system.h"
	
void Game::run()
{
	isRunning = true;

	onCreate();

	isInit = true;

	while(isRunning)
	{
		onUpdate();
	}

	onQuit();
}

void Game::quit()
{
	onQuit();

	isRunning = false;
	Sys_Exit(0);
}