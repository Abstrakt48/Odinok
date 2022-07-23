#ifndef __SYS__
#define __SYS__

typedef enum
{
	et_normal,
	et_error
} EXITYPE;

void Sys_mkdir (const char *path); 	// TODO

void Sys_ShutdownMemory( void ); 	// TODO
void Sys_InitMemory( void ); 		// TODO

void Sys_Sleep ( int msec );
void Sys_OutputDebugString(const char *msg);

void Sys_Printf ( const char *fmt, ... );
void Sys_Error ( const char *error, ... );

void Sys_Exit ( EXITYPE eType );

#endif