#pragma once

#include "mathlib/vector.h"

#define MOVETYPE_NONE 0
#define MOVETYPE_WALK 1			  // Player only - moving on the ground
#define MOVETYPE_STEP 2			  // gravity, special edge handling -- monsters use this
#define MOVETYPE_FLY 3			  // No gravity, but still collides with stuff
#define MOVETYPE_PUSH 4			  // no clip to world, push and crush
#define MOVETYPE_NOCLIP 5		  // No gravity, no collisions, still do velocity/avelocity
#define MOVETYPE_BOUNCE 6		  // Just like Toss, but reflect velocity when contacting surfaces
#define MOVETYPE_FOLLOW 7		  // track movement of aiment

#define SOLID_NOT 0		 // no interaction with other objects
#define SOLID_TRIGGER 1	 // touch on edge, but not blocking
#define SOLID_BBOX 2	 // touch on edge, block

#define DEAD_NO 0	 // alive
#define DEAD_DYING 1 // playing death animation or still falling off of a ledge waiting to hit ground
#define DEAD_DEAD 2	 // dead. lying still.
#define DEAD_RESPAWNABLE 3
#define DEAD_DISCARDBODY 4

#define DAMAGE_NO 0
#define DAMAGE_YES 1

enum
{
	renderNormal,
	renderGlow,
};

typedef struct
{
	byte r, g, b;
} color24;

typedef struct
{
	unsigned r, g, b, a;
} colorVec;

typedef struct
{
	Vector normal;
	float dist;
} plane_t;