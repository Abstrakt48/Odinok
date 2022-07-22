#ifndef __BASETYPES__
#define __BASETYPES__

typedef int mboolean;
typedef unsigned long ulong;
typedef unsigned char byte;
typedef unsigned short word;

typedef unsigned int uintptr_t;

typedef float vec_t;

#ifndef __cplusplus
#define true TRUE
#define false FALSE
#endif

#ifdef __cplusplus
extern "C"
{
#endif
	double __cdecl fabs(double);
#ifdef __cplusplus
}
#endif

inline float FloatMakePositive(vec_t f)
{
	return (float)fabs(f);
}

struct color24
{
	byte r, g, b;
};

typedef struct color32_s
{
	bool operator!=(const struct color32_s& other) const;

	byte r, g, b, a;
} color32;

inline bool color32::operator!=(const color32& other) const
{
	return r != other.r || g != other.g || b != other.b || a != other.a;
}

struct colorVec
{
	unsigned r, g, b, a;
};

#ifdef __cplusplus

struct vrect_t
{
	int	x, y, width, height;
	vrect_t* pnext;
};

#endif


//-----------------------------------------------------------------------------
// Rect, used by
//-----------------------------------------------------------------------------
struct Rect_t
{
	int x, y;
	int width, height;
};


//-----------------------------------------------------------------------------
// Interval, used by 
//-----------------------------------------------------------------------------
struct interval_t
{
	float start;
	float range;
};


#endif // __BASETYPES__