#include "triggers.h"
#include "engine/const.h"

void CFrictionModifier :: Spawn()
{
	pev->solid = SOLID_TRIGGER;
	pev->movetype = MOVETYPE_NONE;
}

void CFrictionModifier::ChangeFriction(CBaseEntity* pEnt)
{
	if (pEnt->pev->movetype != MOVETYPE_BOUNCE)
		pEnt->pev->friction = m_frictionFraction;
}