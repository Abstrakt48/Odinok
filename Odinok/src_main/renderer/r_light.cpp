#include "render.h"
#include "mathlib/vector.h"

void DynamicLight::R_CreateDynamicLight(Vector3D _origin, Vector3D _color, float _radius)
{
	DynamicLight::origin = _origin;
	DynamicLight::color = _color;

	DynamicLight::radius = _radius;
}

void DynamicLight::R_SetDynamicLightOrigin(Vector3D newOrigin)
{
	DynamicLight::origin = newOrigin;
}

void DynamicLight::R_SetDynamicLightColor(Vector3D newColor)
{
	DynamicLight::color = newColor;
}

void DynamicLight::R_SetDynamicLightRadius(float newRadius)
{
	DynamicLight::radius = radius;
}