#include "winApplication.h"
#include "system/system.h"
#include "game/game.h"
#include "tools/basetypes.h"

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

	GM_OrderMain();

	Shutdown();
};

void CWinApplication::Init()
{
	Sys_Printf("Initializing...\n");

	GM_OrderInit();
	Sys_Printf("linuxApplication initialized\n");

	mPostInit = otrue;
};

void CWinApplication::Shutdown()
{
	Sys_Exit(0);
};