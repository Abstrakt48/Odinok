#include "render.h"
#include "tools/mathlib.h"

void Image::R_CreateImage(const char* img, vec2_t dimensions, int frameUsed, 
	oboolean mipmap, imageRenderMode_t renderMode)
{
	Image::imgName = img;

	Image::frameUsed = frameUsed;

	Image::mipmap = mipmap;
	Image::renderMode = renderMode;

	Vector2Copy(Image::dimensions, dimensions);
}