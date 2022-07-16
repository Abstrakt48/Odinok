#ifdef _WIN32
	// if running on windows OS:
	#include <Windows.h>

	#include "win/winApplication.h" 
#else
	#include "linux/linuxApplication.h"
#endif

int main(int argc, char** argv)
{
#ifdef _WIN32
	// if running on windows OS:
	CWinApplication app("");
#else
	// for cases where it runs on linux (windows code will be worked on, then 
	// linux code after)
	CLinuxApplication app();
#endif

	return app.Run();
}