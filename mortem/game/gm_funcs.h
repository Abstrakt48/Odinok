#pragma once

#include "common/cm_public.h"
#include "gm_local.h"

// 
// CFuncRotate
// for rotating entities along every axis (except w)
// 
class CFuncRotate
{
private:
	mBoolean m_isOn = mTrue; // default it to mtrue
public:
	// axis
	void Rotate(entvars_t *pev, rotateAxis axis, float speed);

	// enabling
	void EnableDisable(mBoolean value);
	void Toggle(void);

	// check for wether or not it is on, will return value of m_isOn
	mBoolean IsEnabled(void);
};