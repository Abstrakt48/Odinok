#ifndef __R_LOCAL__
#define __R_LOCAL__

#include "tools/mathlib.h"
#include "tools/basetypes.h"
#include "game/orderdef.h"

typedef enum {
	img_clampToEdge,
	img_repeat
} imageRenderMode_t;

//
// For game images (textures and stuff)
//
class Image
{
private:
	const char *	imgName;					// game path, including extension
	vec2_t			dimensions;

	int				frameUsed;					// for texture usage in frame statistics

	oboolean		mipmap;
	imageRenderMode_t	renderMode;
public:
	void R_CreateImage(const char *img, vec2_t dimensions, int frameUsed,
		oboolean mipmap, imageRenderMode_t renderMode);
};

//
// rLight
//
class DynamicLight
{
public:
	vec3_t	origin;
	vec3_t	color;				// range from 0.0 to 1.0, should be color normalized
	float	radius;
public:
	void R_CreateDynamicLight(vec3_t origin, vec3_t color, float radius);
	void R_SetDynamicLightOrigin(vec3_t newOrigin);
	void R_SetDynamicLightColor(vec3_t newColor);
	void R_SetDynamicLightRadius(float newRadius);
};

typedef struct 
{
	float		cloudHeight;
} skyParams_t;

typedef struct 
{
	vec3_t	color;
	float	depthForOpaque;
} fogParams_t;

typedef struct 
{
	vec3_t		bounds[2];

	unsigned	colorInt;				// in packed byte format
	fogParams_t	params;
} fog_t;

#endif