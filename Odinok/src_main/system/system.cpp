#include "system.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#ifdef __linux__
#include <unistd.h>
#endif

#ifdef _WIN32
#include <Windows.h>
#endif

//-----------------------------------------------------------------------------
// Purpose: Print to system console
// Input  : *fmt 
//			... - 
// Output : void Sys_Printf
//-----------------------------------------------------------------------------
void Sys_Printf(const char *fmt, ...)
{
	va_list		argptr;
	char		text[1024];

	va_start (argptr,fmt);
	vsnprintf (text, sizeof( text ), fmt, argptr);
	va_end (argptr);

	printf( "%s", text );
}

//-----------------------------------------------------------------------------
// Purpose: Exit engine with error
// Input  : *error - 
//			... - 
// Output : void Sys_Error
//-----------------------------------------------------------------------------
void Sys_Error(const char *error, ...)
{
	va_list		argptr;
	char		text[1024];

	va_start (argptr,error);
	vsnprintf (text, sizeof( text ), error, argptr);
	va_end (argptr);

	printf( "[ERROR] %s", text );
}

//-----------------------------------------------------------------------------
// Purpose: Exit engine
// Input  : _ecode - 
//			... - 
// Output : void Sys_Exit
//-----------------------------------------------------------------------------
void Sys_Exit( int _ecode )
{
	exit((int)_ecode); // cast to int, in case param not input as int
}

//-----------------------------------------------------------------------------
// Purpose: Cause system to pause for a set time
// Input  : msec - 
// Output : void Sys_Sleep
//-----------------------------------------------------------------------------
void Sys_Sleep( int msec )
{
#ifdef _WIN32
	Sleep ( msec );
#else
	usleep( msec );
#endif
}

//-----------------------------------------------------------------------------
// Purpose: Sending debug messages to system console
// Input  : *msg - 
// Output : void Sys_OutputDebugString
//-----------------------------------------------------------------------------
void Sys_OutputDebugString(const char *msg)
{
	const char *debug = "DEBUG-> ";

	std::string fullMsg = debug;
	fullMsg += msg;

	const char *fullMsgChar = fullMsg.c_str();

	Sys_Printf( fullMsgChar );
}