#pragma once

class CLinuxApplication
{
public:
	CLinuxApplication(int argc, char** argv);
	~CLinuxApplication();

	void Run();

	void Init();
	void Shutdown();
private:
	bool mPostInit = false;
};
