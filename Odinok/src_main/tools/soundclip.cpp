#include "soundclip.h"
#include "mathlib/mathlib.h"
#include "mathlib/vector.h"

void SoundClip::CreateSoundClip(const char* path, float vol, bool loop)
{
	SoundClip::m_sndPath = path;
	SoundClip::m_sndVolume = vol;

	SoundClip::m_sndLoop = loop;
}

void SoundClip::SetVolume(float newVol)
{
	SoundClip::m_sndVolume = newVol;
}

void SoundClip::SetLoop(bool newLoop)
{
	SoundClip::m_sndLoop = newLoop;
}

void DynamicSoundClip::CreateDynamicSoundClip(const char* path, float vol, float rad, Vector3D pos, bool loop)
{
	DynamicSoundClip::m_sndPath = path;
	DynamicSoundClip::m_sndVolume = vol;
	DynamicSoundClip::m_sndRadius = rad;

	DynamicSoundClip::m_sndLoop = loop;
	
	DynamicSoundClip::m_sndPosition = pos;
}

void DynamicSoundClip::SetVolume(float newVol)
{
	DynamicSoundClip::m_sndVolume = newVol;
}

void DynamicSoundClip::SetRadius(float newRad)
{
	DynamicSoundClip::m_sndRadius = newRad;
}

void DynamicSoundClip::SetPosition(Vector3D newPos)
{
	DynamicSoundClip::m_sndPosition = newPos;
}

void DynamicSoundClip::SetLoop(bool newLoop)
{
	DynamicSoundClip::m_sndLoop = newLoop;
}