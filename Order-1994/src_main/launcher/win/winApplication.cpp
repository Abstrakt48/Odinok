#include "winApplication.h"
#include "engine/sys.h"
#include "game/game.h"
#include "common/types.h"

CWinApplication::CWinApplication(const char* cmdline)
{
	msCmdLine[0] = '\0';

	if (cmdline && *cmdline)
		strcat_s(msCmdLine, cmdline);
};

CWinApplication::~CWinApplication() = default;

void CWinApplication::Run()
{
	// initialize game first
	Init();

	// if code in init function fails, exit with a failure code (1)
	if (!mPostInit)
	{
		Sys_Error("mPostInit not set to true\n");
	}

	Sys_Printf("Working\n");
	Sys_Printf("Attempting to boot game...\n");

	GM_MortemMain();

	Shutdown();
};

void CWinApplication::Init()
{
	Sys_Printf("Initializing...\n");

	GM_MortemInit();
	Sys_Printf("linuxApplication initialized\n");

	mPostInit = mTrue;
};

void CWinApplication::Shutdown()
{
	Sys_Exit(0);
};