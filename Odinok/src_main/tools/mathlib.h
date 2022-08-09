#ifndef __MATHLIB__
#define __MATHLIB__

#include <math.h>

#include "basetypes.h"

typedef float vec_t;

typedef vec_t vec2_t[3];
typedef vec_t vec3_t[3];
typedef vec_t vec4_t[4];

#define	SIDE_FRONT		0
#define	SIDE_ON			2
#define	SIDE_BACK		1
#define	SIDE_CROSS		-2

#define	O_PI	3.14159265358979323846
#define DEG2RAD( a ) ( ( (a) * O_PI ) / 180.0F )
#define RAD2DEG( a ) ( ( (a) * 180.0f ) / O_PI )

// plane types are used to speed some tests
// 0-2 are axial planes
#define	PLANE_X			0
#define	PLANE_Y			1
#define	PLANE_Z			2
#define	PLANE_NON_AXIAL	3

oboolean VectorCompare(const vec3_t v1, const vec3_t v2);

#define DotProduct(x,y) (x[0]*y[0]+x[1]*y[1]+x[2]*y[2])
#define VectorSubtract(a,b,c) {c[0]=a[0]-b[0];c[1]=a[1]-b[1];c[2]=a[2]-b[2];}
#define VectorAdd(a,b,c) {c[0]=a[0]+b[0];c[1]=a[1]+b[1];c[2]=a[2]+b[2];}
//#define VectorCopy(a,b) {b[0]=a[0];b[1]=a[1];b[2]=a[2];}
#define VectorScale(a,b,c) {c[0]=b*a[0];c[1]=b*a[1];c[2]=b*a[2];}
#define VectorClear(x) {x[0] = x[1] = x[2] = 0;}
#define	VectorNegate(x) {x[0]=-x[0];x[1]=-x[1];x[2]=-x[2];}

// Creates a 2D Vector from given parameters
void Vector2Create(vec2_t vec, vec_t x, vec_t y);
// Creates a 3D Vector from given parameters
void Vector3Create(vec3_t vec, vec_t x, vec_t y, vec_t z);
// Creates a 4D Vector from given parameters
void Vector4Create(vec4_t vec, vec_t x, vec_t y, vec_t z, vec_t w);

// Copies the first vector into the second vector
void Vector2Copy(vec2_t a, vec2_t b);
// Copies the first vector into the second vector
void Vector3Copy(vec3_t a, vec3_t b);
// Copies the first vector into the second vector
void Vector4Copy(vec4_t a, vec4_t b);

#endif