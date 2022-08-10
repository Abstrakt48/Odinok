#ifndef __ENTITY__
#define __ENTITY__

#include "tools/string_t.h"
#include "mathlib/vector.h"

typedef enum {
	ET_GENERAL, // for when the entity has no type or no specific type
	ET_PLAYER,
	ET_ITEM,
	ET_BUTTON,
	ET_TRAIN,
	ET_ENEMY,
} entType_t;

typedef struct entVars_s
{
	string_t 		globalname;

	entType_t		type;

	int				flags;

	int 			id;

	Vector3D		mins, maxs;
	Vector3D		absmin, absmax;

	Vector3D		currentOrigin;
	Vector3D		currentAngles;
	Vector3D		currentScale;

	Vector3D		origin;
	Vector3D		angles;
	Vector3D		scale;
	
	string_t		*model;
	int				modelindex;

	int 			frame;

	oboolean		physicsObject; // gonna fkn die when trying to implement physics lol

	int				clipmask;

	string_t		*message;

	float			speed;
	Vector3D		movedir;

	int				health;

	oboolean 		takedamage;

	int				damage;
} entVars_t;

// The base entity class, all entities will derive from this
class BaseEntity
{
public:
	entVars_t *pev = new entVars_t;

	virtual void Precache() {}

	virtual void Spawn() {}
	virtual void Update() {}
	virtual void Use() {}

public:
	// predefined stuff/non-virtual functions
	void SetID(); // Should ALWAYS be at the start of the entity Spawn() function
	int GetID();
};

extern int entityID;

#endif