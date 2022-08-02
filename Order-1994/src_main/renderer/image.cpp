#include "render.h"

void Image::R_CreateImage(const char* img, int width, int height, int frameUsed, 
	oboolean mipmap, imageRenderMode_t renderMode)
{
	Image::imgName = img;

	Image::width = width;
	Image::height = height;

	Image::frameUsed = frameUsed;

	Image::mipmap = mipmap;
	Image::renderMode = renderMode;
}