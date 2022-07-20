#include "gm_funcs.h"
#include "common/cm_public.h"
#include "engine/sys.h"

//======================
// CFuncRotate
//======================
void CFuncRotate :: Rotate(entvars_t *pev, rotateAxis axis, float speed)
{
	if(m_isOn == mTrue)
	{
		pev->angles[(int) axis] += speed;

		if(pev->angles[(int) axis] >= 360.0f)
		{
			pev->angles[(int) axis] = 0.0f;
		}
	}
	else
	{
		Sys_Printf("[Warning] CFuncRotate > m_isOn not set to mTrue\n");
	}
}

void CFuncRotate :: EnableDisable(mBoolean value)
{
	// set the m_isOn variable to value of param
	m_isOn = value;
}

void CFuncRotate :: Toggle(void)
{
	// if(CFuncRotate :: IsEnabled() == mTrue)
	// {
	// 	CFuncRotate :: EnableDisable(mFalse);
	// }
	// else if(CFuncRotate :: IsEnabled() == mFalse)
	// {
	// 	CFuncRotate :: EnableDisable(mTrue);
	// }

	bool setTo;

	setTo = (bool) !m_isOn;
	CFuncRotate :: EnableDisable((int)setTo);
}

mBoolean CFuncRotate :: IsEnabled(void)
{
	// returns value of m_isOn
	return m_isOn;
}