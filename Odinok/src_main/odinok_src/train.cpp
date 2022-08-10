#include "train.h"
#include "mathlib/mathlib.h"
#include "mathlib/vector.h"
#include "system/system.h"

void TrainEntity::Precache()
{
	// insert precache code here (models and sounds and stuff)
}

void TrainEntity::SetAxis(axis_t axis)
{
	TrainEntity::axis = axis;
}

void TrainEntity::SetSpeed(float speed)
{
	TrainEntity::pev->speed = speed;
}

void TrainEntity::Spawn()
{
	SetID();

	pev->globalname = MAKE_STRING("ent_train");
	pev->type = ET_TRAIN;

	pev->physicsObject = ofalse; // make sure this entity is not effected by physics

	pev->origin = vec_origin;

	SetSpeed(0);
	SetAxis(axis_x); // default to move along x axis
}

void TrainEntity::Update()
{
	if(axis == axis_x)
		pev->origin.x += pev->speed;
	else if(axis == axis_y)
		pev->origin.y += pev->speed;
	else if(axis == axis_z)
		pev->origin.z += pev->speed;
}