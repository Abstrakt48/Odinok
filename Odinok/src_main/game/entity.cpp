#include "entity.h"
#include "system/system.h"

int entityID = 0;

void BaseEntity::SetID()
{
	// increment the public id for each entity
	if (pev->id == NULL)
	{
		entityID += 1;
		pev->id = entityID;
	}
	else
	{
		Sys_Printf("%s's ID is already set to %d\n", pev->globalname, pev->id);
	}
}

int BaseEntity::GetID()
{
	// return the public id of the current entity
	return pev->id;
}