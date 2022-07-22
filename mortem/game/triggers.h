#pragma once

#include "cbase.h"

class CFrictionModifier : public CBaseEntity
{
public:
	void Spawn() override;
	void ChangeFriction(CBaseEntity *pEnt);

	float m_frictionFraction;
};	