#pragma once

#include "tier0/basetypes.h"

class CLinuxApplication
{
public:
	CLinuxApplication(int argc, char** argv);
	~CLinuxApplication();

	void Run();

	void Init();
	void Shutdown();
private:
	mboolean mPostInit = mFalse;
};
