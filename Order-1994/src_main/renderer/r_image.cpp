#include "r_local.h"

image_t* R_CreateImage(const char* img, int width, int height, int frameUsed, oboolean mipmap, wrapClampMode_t wrapClampMode)
{
	image_t* retImg = new image_t;

	retImg->imgName = img;
	retImg->frameUsed = frameUsed;
	retImg->mipmap = mipmap;
	retImg->wrapClampMode = wrapClampMode;
	retImg->width = width;
	retImg->height = height;
	
	return retImg;
}
