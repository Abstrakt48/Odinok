#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

class CWinApplication
{
public:
	CWinApplication(const char* cmdline);
	~CWinApplication();

	void Run();

	void Init();
	void Shutdown();
private:
	bool mPostInit = false;
protected:
	char msCmdLine[512]{};
};
