#include "linuxApplication.h"
#include "engine/sys.h"
#include "game/gm_local.h"
#include "common/cm_public.h"

CLinuxApplication::CLinuxApplication(int argc, char** argv)
{
};

CLinuxApplication::~CLinuxApplication() = default;

int CLinuxApplication::Run()
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

void CLinuxApplication::Init()
{
	Sys_Printf("Initializing...\n");

	GM_MortemInit();
	Sys_Printf("linuxApplication initialized\n");

	mPostInit = mTrue;
};

void CLinuxApplication::Shutdown()
{
	Sys_Exit(et_normal);
};