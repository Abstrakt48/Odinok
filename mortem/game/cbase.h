#pragma once

#include "gm_local.h"
#include "gm_funcs.h"

class CBaseEntity
{
public:
	entvars_t *pev = new entvars_t;

	virtual void Spawn();

	virtual void Think	(entvars_t *pev);
	virtual void Use	(entvars_t *pev, entvars_t *pevOther, entvars_t *pevActivator);
	virtual void Pain	(entvars_t *pev, entvars_t *pevAttacker, int damage);
	virtual void Die 	(entvars_t *pev, entvars_t *pevInflictor, string_t *message);
};