#ifndef __BASETYPES__
#define __BASETYPES__

#ifndef NULL
#define NULL 0
#endif

#define uFullSecond 	1000000 // Used for usleep, one full second is 1000000 useconds.
								// To get more than one second in a sleep func, multiply
								// by number of seconds (can be float or int).

typedef int oboolean;
#define otrue 1
#define ofalse 0

typedef unsigned long ulong;
typedef unsigned char byte;
typedef unsigned short word;

#endif