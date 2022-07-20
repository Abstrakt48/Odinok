#pragma once

#include "common/cm_public.h"

// 
// CFuncRotate
// for rotating entities along every axis (except w)
// 
class CFuncRotate
{
private:
	mBoolean isOn = mTrue; // default it to mtrue
public:
	// axis
	void Rotate(gentity_t *entity, rotateAxis axis, float speed);

	// enabling
	void EnableDisable(mBoolean value);
	void Toggle(void);

	// check for wether or not it is on, will return value of isOn
	mBoolean IsEnabled(void);
};

//======================
// CFuncRotate :: Rotate
//======================
void CFuncRotate :: Rotate(gentity_t *entity, rotateAxis axis, float speed)
{
	if(ison == mtrue)
	{
		entity->angles[(int) axis] += speed;

		if(entity->angles[(int) axis] >= 360.0f)
		{
			entity->angles[(int) axis] = 0.0f;
		}
	}
}

//======================
// CFuncRotate :: EnableDisable
//======================
void CFuncRotate :: EnableDisable(mBoolean value)
{
	// set the ison variable to value of param
	isOn = value;
}

//======================
// CFuncRotate :: Toggle
//======================
void CFuncRotate :: Toggle(void)
{
	if(CFuncRotate :: IsEnabled() == mTrue)
	{
		CFuncRotate :: EnableDisable(mFalse);
	}
	else if(CFuncRotate :: IsEnabled() == mFalse)
	{
		CFuncRotate :: EnableDisable(mTrue);
	}
}

//======================
// CFuncRotate :: IsEnabled
//======================
mBoolean CFuncRotate :: IsEnabled(void)
{
	// returns value of ison
	return isOn;
}