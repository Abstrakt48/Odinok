#include "winApplication.h"
#include "engine/sys.h"
#include "game/gm_local.h"

CWinApplication::CWinApplication(const char* cmdline)
{
	msCmdLine[0] = '\0';

	if (cmdline && *cmdline)
		strcat_s(msCmdLine, cmdline);
};

CWinApplication::~CWinApplication() = default;

int CWinApplication::Run()
{
	// initialize game first
	Init();

	// if code in init function fails, exit with a failure code (1)
	if (!mPostInit)
	{
		Sys_Error("mPostInit not set to true\n");
		return EXIT_FAILURE;
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

	if (isGameInit)
		Sys_Printf("winApplication initialized\n");
	else
		Sys_Error("isGameInit set to mFalse or NULL\n");

	mPostInit = true;
};

int CWinApplication::Shutdown()
{
	Sys_Exit(et_normal);
	return EXIT_SUCCESS;
};