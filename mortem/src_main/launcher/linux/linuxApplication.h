#pragma once

class CLinuxApplication
{
public:
	CLinuxApplication(int argc, char** argv);
	~CLinuxApplication();

	int Run();

	void Init();
	void Shutdown();
private:
	bool mPostInit = false;
};
