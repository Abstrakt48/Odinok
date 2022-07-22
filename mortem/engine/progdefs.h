#pragma once

#include "mathlib/mathlib.h"
#include "mathlib/vector.h"
#include "common/cm_public.h"

typedef struct
{
	float time;
	float frametime;

	string_t mapname;

	Vector v_forward;
	Vector v_up;
	Vector v_right;

	int maxClients;
	int maxEntities;
} globalvars_t;

typedef struct entvars_s
{
	string_t classname;
	string_t globalname;

	Vector origin;
	Vector oldorigin;
	Vector velocity;
	Vector basevelocity;
	
	Vector movedir;

	Vector angles;	   // Model angles
	Vector avelocity;  // angle velocity (degrees per second)
	Vector punchangle; // auto-decaying view angle adjustment
	Vector v_angle;	   // Viewing angle (player only)

	// For parametric entities
	Vector endpos;
	Vector startpos;
	float impacttime;
	float starttime;

	int modelindex;
	string_t model;

	int viewmodel;	 // player's viewmodel
	int weaponmodel; // what other players see

	Vector absmin; // BB max translated to world coord
	Vector absmax; // BB max translated to world coord
	Vector mins;   // local BB min
	Vector maxs;   // local BB max
	Vector size;   // maxs - mins

	float ltime;
	float nextthink;

	int movetype;
	int solid;

	float gravity;	// % of "normal" gravity
	float friction; // inverse elasticity of MOVETYPE_BOUNCE

	int sequence;		// animation sequence
	int gaitsequence;	// movement animation sequence for player (0 for none)
	float frame;		// % playback position in animation sequences (0..255)
	float animtime;		// world time when frame was set
	float framerate;	// animation playback rate (-8x to 8x)

	byte scale; // sprite rendering scale (0..255)

	int rendermode;
	Vector rendercolor;
	int renderfx;

	float health;
	int weapons; // bit mask for available weapons
	float takedamage;

	int deadflag;
	Vector view_ofs; // eye position

	int button;
	int impulse;
	
	entvars_s* owner;

	int spawnflags;
	int flags;

	int team;

	float max_health;
	float armortype;
	float armorvalue;
	
	string_t target;
	string_t targetname;
	string_t message;

	float dmg_take;
	float dmg_save;
	float dmg;
	float dmgtime;

	string_t noise;
	string_t noise1;
	string_t noise2;
	string_t noise3;

	float speed;

	int playerclass;
	float maxspeed;

	float fov;
	int weaponanim;

	int pushmsec;

	int gamestate;

	int oldbuttons;
} entvars_t;
