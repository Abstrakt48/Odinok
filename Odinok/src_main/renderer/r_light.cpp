#include "render.h"

void DynamicLight::R_CreateDynamicLight(vec3_t _origin, vec3_t _color, float _radius)
{
	for (int i = 0; i < 3; i++)
	{
		Vector3Copy(DynamicLight::origin, _origin);
		Vector3Copy(DynamicLight::color, _color);
	}

	DynamicLight::radius = _radius;
}

void DynamicLight::R_SetDynamicLightOrigin(vec3_t newOrigin)
{
	Vector3Copy(DynamicLight::origin, newOrigin);
}

void DynamicLight::R_SetDynamicLightColor(vec3_t newColor)
{
	Vector3Copy(DynamicLight::color, newColor);
}

void DynamicLight::R_SetDynamicLightRadius(float newRadius)
{
	DynamicLight::radius = radius;
}