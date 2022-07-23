#include "linuxApplication.h"
#include "engine/sys.h"
#include "tier0/basetypes.h"
#include "game/game.h"

#include <cstdlib>

CLinuxApplication::CLinuxApplication(int argc, char** argv)
{
};

CLinuxApplication::~CLinuxApplication() = default;

void CLinuxApplication::Run()
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

void CLinuxApplication::Init()
{
	Sys_Printf("Initializing...\n");

	GM_MortemInit();
	Sys_Printf("linuxApplication initialized\n");

	mPostInit = mTrue;
};

void CLinuxApplication::Shutdown()
{
	Sys_Exit(0);
};