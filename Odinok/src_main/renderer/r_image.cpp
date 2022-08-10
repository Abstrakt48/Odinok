#include "render.h"
#include "mathlib/mathlib.h"
#include "mathlib/vector.h"

void Image::R_CreateImage(const char* img, Vector2D dimensions, int frameUsed, 
	oboolean mipmap)
{
	Image::imgName = img;

	Image::frameUsed = frameUsed;

	Image::mipmap = mipmap;

	Image::dimensions.x = dimensions.x;
	Image::dimensions.y = dimensions.y;
}