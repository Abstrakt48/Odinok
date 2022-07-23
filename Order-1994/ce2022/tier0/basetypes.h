#ifndef __BASETYPES__
#define __BASETYPES__

#ifndef NULL
#define NULL 0
#endif

#define M_PI			3.14159265358979323846

#ifndef min
	#define min(a,b)  (((a) < (b)) ? (a) : (b))
#endif

#ifndef max
	#define max(a,b)  (((a) > (b)) ? (a) : (b))
#endif

#ifndef FALSE
#define FALSE 0
#define TRUE (!FALSE)
#endif

typedef int mboolean;
#define mTrue 1
#define mFalse 0

typedef unsigned long ulong;
typedef unsigned char byte;
typedef unsigned short word;

typedef unsigned int uintptr_t;

typedef float vec_t;

#ifndef __cplusplus
#define true TRUE
#define false FALSE
#endif

struct color24
{
	byte r, g, b;
};

typedef struct color32_s
{
	bool operator!=( const struct color32_s &other ) const;

	byte r, g, b, a;
} color32;

inline bool color32::operator!=( const color32 &other ) const
{
	return r != other.r || g != other.g || b != other.b || a != other.a;
}

struct colorVec
{
	unsigned r, g, b, a;
};

#endif