#ifndef __RENDER__
#define __RENDER__

#include "mathlib/mathlib.h"
#include "tools/basetypes.h"
#include "mathlib/vector.h"

//
// For game images (textures and stuff)
//
class Image
{
public:
	const char *		imgName;					// game path, including extension
	Vector2D			dimensions;

	int					frameUsed;					// for texture usage in frame statistics

	oboolean			mipmap;
public:
	Image();
	Image(const char *img, Vector2D dimensions, int frameUsed,
		oboolean mipmap);

	void R_CreateImage(const char *img, Vector2D dimensions, int frameUsed,
		oboolean mipmap);
};

//
// rLight
//
class DynamicLight
{
public:
	Vector3D	origin;
	Vector3D	color;				// range from 0.0 to 1.0, should be color normalized
	float	radius;
public:
	DynamicLight();
	DynamicLight(Vector3D origin, Vector3D color, float radius);

	void R_CreateDynamicLight(Vector3D origin, Vector3D color, float radius);
	void R_SetDynamicLightOrigin(Vector3D newOrigin);
	void R_SetDynamicLightColor(Vector3D newColor);
	void R_SetDynamicLightRadius(float newRadius);
};

typedef struct 
{
	float		cloudHeight;
} skyParams_t;

typedef struct 
{
	Vector3D	color;
	float	depthForOpaque;
} fogParams_t;

typedef struct 
{
	Vector3D		bounds[2];

	unsigned	colorInt;				// in packed byte format
	fogParams_t	params;
} fog_t;

#endif