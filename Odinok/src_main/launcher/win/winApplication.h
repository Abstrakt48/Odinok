#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "tools/basetypes.h"

class CWinApplication
{
public:
	CWinApplication(const char* cmdline);
	~CWinApplication();

	void Run();

	void Init();
	void Shutdown();
private:
	oboolean mPostInit = ofalse;
protected:
	char msCmdLine[512]{};
};
