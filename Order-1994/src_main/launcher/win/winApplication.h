#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "tier0/basetypes.h"

class CWinApplication
{
public:
	CWinApplication(const char* cmdline);
	~CWinApplication();

	void Run();

	void Init();
	void Shutdown();
private:
	mboolean mPostInit = mFalse;
protected:
	char msCmdLine[512]{};
};
