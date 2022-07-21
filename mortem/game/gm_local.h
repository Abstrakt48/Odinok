#pragma once

#include "mathlib/mathlib.h"
#include "mathlib/vector.h"
#include "common/cm_public.h"

typedef struct entvars_s
{
	int			entityindex;			// entity index

	Vector		origin;
	Vector		angles;

	int			modelindex;
	int			frame;

	int			solid;					// for client side prediction, trap_linkentity sets this properly

	int			event;					// impulse events -- muzzle flashes, footsteps, etc
	int			eventparam;

	// for players
	int			powerups;				// bit flags
	int			weapon;					// determines weapon and flash model, etc

	Vector		mins, maxs;
	int			contents;				// CONTENTS_TRIGGER, CONTENTS_SOLID, CONTENTS_BODY, etc
										// a non-solid entity should set to 0

	Vector		absmin, absmax;			// derived from mins/maxs and origin + rotation

	// currentorigin will be used for all collision detection
	Vector		currentorigin;
	Vector		currentangles;

	string_t	*classname;
	int			spawnflags;

	int			flags;

	char		*model;

	int			clipmask;				// brushes with this content value will be collided against	
										// when moving.

	string_t	*message;				// messages for deaths & others

	float		speed;
	Vector		movedir;

	int			nextthink;
	void		(*think)(entvars_s *pev);
	void		(*use)(entvars_s *pev, entvars_s *pevOther, entvars_s *pevActivator);
	void		(*pain)(entvars_s *pev, entvars_s *pevAttacker, int damage);
	void		(*die)(entvars_s *pev, entvars_s *pevInflictor, string_t *message);

	int			health;

	mBoolean	takedamage;
	int			damage;
} entvars_t;

// Game initialization method
int GM_MortemInit( void );

// Main game method
void GM_MortemMain( void );