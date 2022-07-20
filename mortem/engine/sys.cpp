#include "sys.h"
#include "common/cm_public.h"

#include <stdio.h>
#include <cstdarg>
#include <cstring>
#include <stdlib.h>

#ifdef _WIN32
#include <Windows.h>
#elif __linux__
#include <unistd.h>
#endif

//
// Sys_Printf
//
void Sys_Printf(const char* fmt, ...)
{
	va_list argptr;

#ifdef _WIN32
	char text[1024];

	va_start(argptr, fmt);
	vsprintf_s(text, fmt, argptr);
	va_end(argptr);

	printf("%s", text);

#elif __linux__
	char text[1024];
	byte* p;

	va_start(argptr, fmt);
	vsprintf(text, fmt, argptr);
	va_end(argptr);

	if (strlen(text) > sizeof(text))
		Sys_Error("memory overwrite in Sys_Printf\n");

	for (p = (byte*)text; *p; p++)
	{
		*p &= 0x7f;
		if ((*p > 128 || *p < 32) && *p != 10 && *p != 13 && *p != 9)
			printf("[%02x]", *p);
		else
			putc(*p, stdout);
	};
#endif // _WIN32
};

//
// Sys_Error
//
void Sys_Error(const char* error, ...)
{
	va_list argptr;

#ifdef _WIN32
	char text[1024];

	va_start(argptr, error);
	vsprintf_s(text, error, argptr);
	va_end(argptr);

	Sys_Printf("Sys_Error: %s", text);

	Sys_Exit(et_error);
#elif __linux__
	char string[1024];

	va_start(argptr, error);
	vsprintf(string, error, argptr);
	va_end(argptr);
	Sys_Printf("Sys_Error: %s", string);

	Sys_Exit(et_error);
#endif
};

//
// Sys_Exit
//
void Sys_Exit(EXIT_TYPE eType)
{
	switch (eType)
	{
	case et_normal:
		exit(0);
		break;
	case et_error:
		exit(1);
		break;
	default:
		exit(0);
		break;
	};
}