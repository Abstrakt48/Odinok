#ifndef __ENTBASE__
#define __ENTBASE__

#include "public/string_t.h"
#include "tools/mathlib.h"

typedef enum {
	ET_GENERAL, // for when the entity has no type, better just to default it to this
	ET_PLAYER,
	ET_ITEM,
	ET_BUTTON,
	ET_TRAIN,
	ET_ENEMY,
} entType_t;

typedef struct entvars_s
{
	string_t 		classname;
	string_t 		globalname;

	entType_t		entType;
	int				entFlags;

	int				flags;

	vec3_t			mins, maxs;
	vec3_t			absmin, absmax;

	vec3_t			currentOrigin;
	vec3_t			currentAngles;

	vec3_t			origin;

	vec3_t			angles;
	
	string_t		*model;
	int				modelindex;

	int 			frame;

	oboolean		physicsObject; // gonna fkn die when trying to implement physics lol

	int				clipmask;

	string_t		*message;

	float			speed;
	vec3_t			movedir;

	int				health;

	oboolean 		takedamage;

	int				damage;
} entvars_t;

class ent_base
{
public:
	entvars_t *pev = new entvars_t;

	virtual void Precache() {}

	virtual void Spawn() {}
	virtual void Think() {}
	virtual void Touch() {}
	virtual void Use() {}
	virtual void TakeDamage(float damage) {}
};

#endif