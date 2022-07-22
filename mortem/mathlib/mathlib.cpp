#include "mathlib.h"
#include "vector.h"

bool VectorCompare(const float* v1, const float* v2)
{
	int i;

	for (i = 0; i < 3; i++)
		if (v1[i] != v2[i])
			return false;

	return true;
}

void VectorMA(const float* veca, float scale, const float* vecb, float* vecc)
{
	vecc[0] = veca[0] + scale * vecb[0];
	vecc[1] = veca[1] + scale * vecb[1];
	vecc[2] = veca[2] + scale * vecb[2];
}

void CrossProduct(const float* v1, const float* v2, float* cross)
{
	cross[0] = v1[1] * v2[2] - v1[2] * v2[1];
	cross[1] = v1[2] * v2[0] - v1[0] * v2[2];
	cross[2] = v1[0] * v2[1] - v1[1] * v2[0];
}

float Length(const float* v)
{
	int i;
	float length = 0.0f;

	for (i = 0; i < 3; i++)
		length += v[i] * v[i];
	length = sqrt(length); // FIXME

	return length;
}

float VectorNormalize(float* v)
{
	float length, ilength;

	length = v[0] * v[0] + v[1] * v[1] + v[2] * v[2];
	length = sqrt(length); // FIXME

	if (0 != length)
	{
		ilength = 1 / length;
		v[0] *= ilength;
		v[1] *= ilength;
		v[2] *= ilength;
	}

	return length;
}

void VectorInverse(float* v)
{
	v[0] = -v[0];
	v[1] = -v[1];
	v[2] = -v[2];
}

void VectorScale(const float* in, float scale, float* out)
{
	out[0] = in[0] * scale;
	out[1] = in[1] * scale;
	out[2] = in[2] * scale;
}
