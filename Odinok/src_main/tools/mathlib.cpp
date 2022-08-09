#include "mathlib.h"
#include "basetypes.h"

oboolean VectorCompare(const vec3_t v1, const vec3_t v2)
{
	if (v1[0] != v2[0] || v1[1] != v2[1] || v1[2] != v2[2]) {
		return ofalse;
	}
	return otrue;
}

void Vector2Create(vec2_t vec, vec_t x, vec_t y)
{
	vec[0] = x;
	vec[1] = y;
}

void Vector3Create(vec3_t vec, vec_t x, vec_t y, vec_t z)
{
	vec[0] = x;
	vec[1] = y;
	vec[2] = z;
}

void Vector4Create(vec4_t vec, vec_t x, vec_t y, vec_t z, vec_t w)
{
	vec[0] = x;
	vec[1] = y;
	vec[2] = z;
	vec[3] = w;
}

void Vector2Copy(vec2_t a, vec2_t b)
{
	for (int i = 0; i < 2; i++)
	{
		a[i] = b[i];
	}
}

void Vector3Copy(vec3_t a, vec3_t b)
{
	for (int i = 0; i < 3; i++)
	{
		a[i] = b[i];
	}
}

void Vector4Copy(vec4_t a, vec4_t b)
{
	for (int i = 0; i < 4; i++)
	{
		a[i] = b[i];
	}
}