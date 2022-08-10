#include "odinok.h"
#include "system/system.h"

#include <string>

int main()
{
	try
	{
		Odinok odinok;
		odinok.run();
	}
	catch (const std::exception& e)
	{
		std::string s = "Error: ";
		s += e.what();
		Sys_Printf("%s\n", s.c_str());
	}
}