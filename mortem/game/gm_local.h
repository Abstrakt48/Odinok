#pragma once

#include "mathlib/mathlib.h"
#include "common/cm_public.h"

typedef struct entvars_s entvars_t;

struct entvars_t 
{
	int			entityindex;			// entity index

	vec3_t		origin;
	vec3_t		angles;

	int			modelindex;
	int			frame;

	int			solid;					// for client side prediction, trap_linkentity sets this properly

	int			event;					// impulse events -- muzzle flashes, footsteps, etc
	int			eventparam;

	// for players
	int			powerups;				// bit flags
	int			weapon;					// determines weapon and flash model, etc

	vec3_t		mins, maxs;
	int			contents;				// CONTENTS_TRIGGER, CONTENTS_SOLID, CONTENTS_BODY, etc
										// a non-solid entity should set to 0

	vec3_t		absmin, absmax;			// derived from mins/maxs and origin + rotation

	// currentorigin will be used for all collision detection
	vec3_t		currentorigin;
	vec3_t		currentangles;

	string_t	*classname;
	int			spawnflags;

	int			flags;

	char		*model;

	int			clipmask;				// brushes with this content value will be collided against	
										// when moving.

	string_t	*message;				// messages for deaths & others

	float		speed;
	vec3_t		movedir;

	int			nextthink;
	void		(*think)(gentity_t *self);
	void		(*use)(gentity_t *self, gentity_t *other, gentity_t *activator);
	void		(*pain)(gentity_t *self, gentity_t *attacker, int damage);
	void		(*die)(gentity_t *self, gentity_t *inflictor, string_t *message);

	int			health;

	mBooleab	takedamage;
	int			damage;
};

// Game initialization method
int GM_MortemInit( void );

// Main game method
void GM_MortemMain( void );