#include "render.h"
#include "mathlib/mathlib.h"
#include "mathlib/vector.h"

Image::Image()
{
	Image::imgName = "textures/placeholder_tex00.png"; // noted as this because this will always exist in every game

	Image::frameUsed = 0; // 0 indexing

	Image::mipmap = otrue;

	Image::dimensions.x = 64;
	Image::dimensions.y = 64;
}

Image::Image(const char* img, Vector2D dimensions, int frameUsed, 
	oboolean mipmap)
{
	Image::imgName = img;

	Image::frameUsed = frameUsed;

	Image::mipmap = mipmap;

	Image::dimensions.x = dimensions.x;
	Image::dimensions.y = dimensions.y;
}

void Image::R_CreateImage(const char* img, Vector2D dimensions, int frameUsed, 
	oboolean mipmap)
{
	Image::imgName = img;

	Image::frameUsed = frameUsed;

	Image::mipmap = mipmap;

	Image::dimensions.x = dimensions.x;
	Image::dimensions.y = dimensions.y;
}