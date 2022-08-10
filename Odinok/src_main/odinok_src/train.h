#ifndef __TRAIN__
#define __TRAIN__

#include "game/entity.h"
#include "mathlib/vector.h"
#include "mathlib/mathlib.h"

class TrainEntity : public BaseEntity
{
public:
	// overrides
	void Precache() override;

	void Spawn() override;
	void Update() override;

public:
	// custom functions
	axis_t axis;
	
	void SetAxis(axis_t axis);
	void SetSpeed(float speed);
};

#endif