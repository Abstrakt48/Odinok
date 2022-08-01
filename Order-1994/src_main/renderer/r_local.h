#ifndef __R_LOCAL__
#define __R_LOCAL__

#include "tools/mathlib.h"
#include "tools/basetypes.h"
#include "game/orderdef.h"

typedef enum {
	IMG_CLAMP_TO_EDGE,
	IMG_REPEAT
} wrapClampMode_t;

//
// For game images
//
typedef struct image_s {
	const char *	imgName;					// game path, including extension
	int				width, height;				// dimensions[0] = width, dimensions[1] = height

	int				frameUsed;					// for texture usage in frame statistics

	oboolean		mipmap;
	wrapClampMode_t	wrapClampMode;
} image_t;

//
// rLight
//
typedef struct dlight_s {
	vec3_t	origin;
	vec3_t	color;				// range from 0.0 to 1.0, should be color normalized
	float	radius;
} dlight_t;

typedef struct {
	float		cloudHeight;
	image_t*	outerbox[6], * innerbox[6];
} skyParams_t;

typedef struct {
	vec3_t	color;
	float	depthForOpaque;
} fogParams_t;

image_t* R_CreateImage(const char *img, int width, int height, int frameUsed, oboolean mipmap, wrapClampMode_t wrapClampMode);

#endif