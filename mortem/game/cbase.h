#pragma once

#include "gm_local.h"
#include "engine/progdefs.h"
#include "engine/const.h"

// damage types
#define DMG_NORMAL 0

// class types
#define CLASS_NONE 0
#define CLASS_MACHINE 1
#define CLASS_PLAYER 2
#define CLASS_HUMAN_PASSIVE 3
#define CLASS_HUMAN_HOSTILE 4
#define CLASS_PLAYER_ALLY 5

class CBaseEntity;
class CBaseMonster;
class CBasePlayerItem;

//
// base entity class
//
class CBaseEntity
{
public:
	// Constructor
	entvars_t* pev;

	virtual ~CBaseEntity() {}

	// initialization functions
	virtual void Spawn() {}
	virtual void Precache() {}
	virtual void Activate() {}

	// Setup the object->object collision box (pev->mins / pev->maxs is the object->world collision box)
	virtual void SetObjectCollisionBox() {}

	// Classify - returns the type of group
	virtual int Classify() { return CLASS_NONE; }

	virtual bool TakeDamage(entvars_t* pevInflictor, entvars_t* pevAttacker, float flDamage, int bitsDamageType) {}
	virtual bool TakeHealth(float flHealth, int bitsDamageType) {}
	virtual void Killed(entvars_t* pevAttacker, int iGib) {}
	virtual bool IsTriggered(CBaseEntity* pActivator) { return true; }
	virtual bool AddPlayerItem(CBasePlayerItem* pItem) { return 0; }
	virtual bool RemovePlayerItem(CBasePlayerItem* pItem) { return 0; }
	virtual int GiveAmmo(int iAmount, const char* szName, int iMax) { return -1; }
	virtual bool IsMoving() { return pev->velocity != g_vecZero; }
	
	virtual void StartSneaking() {}
	virtual void StopSneaking() {}
	virtual bool IsSneaking() { return false; }
	virtual bool IsAlive() { return (pev->deadflag == DEAD_NO) && pev->health > 0; }
	virtual bool IsInWorld() {}
	virtual bool IsPlayer() { return false; }

	virtual CBaseEntity* Respawn() { return NULL; }

	virtual Vector Center() { return (pev->absmax + pev->absmin) * 0.5; } // center point of entity
	virtual Vector EyePosition() { return pev->origin + pev->view_ofs; }  // position of eyes
	virtual Vector EarPosition() { return pev->origin + pev->view_ofs; }  // position of ears
	virtual Vector BodyTarget(const Vector& posSrc) { return Center(); }  // position to shoot at

	// vars to store ammo count
	int ammo_9mm;
	int ammo_762;
	int ammo_556;
	int ammo_12bore;
	int ammo_hairspray;
	int ammo_rockets;

	// stuff for grenades
	float m_flStartThrow;
	float m_flReleaseThrow;
	int m_chargeReady;
	int m_fInAttack;

	int m_fireState;
};

class CWorld : public CBaseEntity
{
public:
	void Spawn() override;
	void Precache() override;
};