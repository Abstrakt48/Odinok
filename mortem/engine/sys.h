#pragma once

typedef enum
{
	et_normal,
	et_error
} EXIT_TYPE;

//
// system IO
//
void Sys_Error(const char* error, ...);
// an error will cause the entire program to exit

void Sys_Printf(const char* fmt, ...);
// send text to the console

void Sys_Exit(EXIT_TYPE eType);

double Sys_FloatTime();

void Sys_Sleep();

void Sys_InitArgv(char* lpCmdLine);