#include "render.h"

void DynamicLight::R_CreateDynamicLight(vec3_t _origin, vec3_t _color, float _radius)
{
	VectorCopy(DynamicLight::origin, _origin);
	VectorCopy(DynamicLight::color, _color);

	DynamicLight::radius = _radius;
}

void DynamicLight::R_SetDynamicLightOrigin(vec3_t newOrigin)
{
	VectorCopy(DynamicLight::origin, newOrigin);
}

void DynamicLight::R_SetDynamicLightColor(vec3_t newColor)
{
	VectorCopy(DynamicLight::color, newColor);
}

void DynamicLight::R_SetDynamicLightRadius(float newRadius)
{
	DynamicLight::radius = radius;
}