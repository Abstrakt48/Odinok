#pragma once

#include "cbase.h"

// maybe used for ice or something? idk, not nesecarrily essential
// but could be useful.
class CFrictionModifier : public CBaseEntity
{
public:
	void Spawn() override;
	void ChangeFriction(CBaseEntity *pEnt);

	float m_frictionFraction;
};	