#pragma once

#include "tools/basetypes.h"

class CLinuxApplication
{
public:
	CLinuxApplication(int argc, char** argv);
	~CLinuxApplication();

	void Run();

	void Init();
	void Shutdown();
private:
	oboolean m_postInit = ofalse;
};
