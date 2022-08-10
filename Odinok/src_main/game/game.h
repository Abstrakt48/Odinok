#ifndef __GAME__
#define __GAME__

//
// Game
// 
class Game
{
public:
	virtual void onCreate() {}
	virtual void onUpdate() {}
	virtual void onQuit() {}
	
	void run();
	void quit();
protected:
	bool isInit;
	bool isRunning;
};

#endif