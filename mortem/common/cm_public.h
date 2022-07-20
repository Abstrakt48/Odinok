#pragma once

#define mTrue 1
#define mFalse 0
typedef int mBoolean;

typedef const char *string_t;

typedef unsigned char byte;
typedef unsigned short word;

enum rotateAxis
{
	// roll pitch yaw (x y z)
	RA_ROLL,
	RA_PITCH,
	RA_YAW,
};

// For exiting, 1 causes fail, 0 runs smoothly
#define Success 0
#define Failure 1