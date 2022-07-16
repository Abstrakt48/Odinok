#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define WIN_BASE_DIR "C:/Users/james/Documents/programming/c++/mortem/"

class CWinApplication
{
public:
	CWinApplication(const char* cmdline);
	~CWinApplication();

	int Run();

	void Init();
	int Shutdown();
private:
	bool mPostInit = false;
protected:
	char msCmdLine[512]{};
};
