#include "linuxApplication.h"
#include "engine/sys.h"

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
	Sys_Printf("Writing to file...\n");

	Shutdown();
};

void CLinuxApplication::Init()
{
	printf("Initializing...\n");
	// code to be initialized goes here
	printf("linuxApplication initialized\n");

	mPostInit = true;
};

int CLinuxApplication::Shutdown()
{
	Sys_Exit(et_normal);
	return EXIT_SUCCESS;
};