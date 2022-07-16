#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// do this once on linux machine
#define LINUX_BASE_DIR ""

class CLinuxApplication
{
public:
	CLinuxApplication(int argc, char** argv);
	~CLinuxApplication();

	int Run();

	void Init();
	int Shutdown();
private:
	bool mPostInit = false;
};
