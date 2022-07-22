#include <stdlib.h>
#include <memory.h>
#include <string.h>

#include "cm_local.h"

//======================
// Mem_Malloc
//======================
void *Mem_Malloc( size_t size )
{
	return( malloc( size ) );
}

//======================
// Mem_ZeroMalloc
//======================
void *Mem_ZeroMalloc( size_t size )
{
	void *pointer;

	pointer = malloc( size );
	memset( ( unsigned char *) pointer, 0, size );
	return( pointer );
}

//======================
// Mem_Realloc
//======================
void *Mem_Realloc( void *memblock, size_t size )
{
	return( realloc( memblock, size ) );
}

//======================
// Mem_Calloc
//======================
void *Mem_Calloc( int num, size_t size )
{
	return( calloc( num, size ) );
}

//======================
// Mem_Strdup
//======================
char *Mem_Strdup( const char *strSource )
{
	return( strdup( strSource ) );
}

//======================
// Mem_Free
//======================
void Mem_Free( void *pointer )
{
	free( pointer );
}
