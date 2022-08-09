#include "soundclip.h"
#include "mathlib.h"

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

void DynamicSoundClip::CreateDynamicSoundClip(const char* path, float vol, float rad, vec3_t pos, bool loop)
{
	DynamicSoundClip::m_sndPath = path;
	DynamicSoundClip::m_sndVolume = vol;
	DynamicSoundClip::m_sndRadius = rad;

	DynamicSoundClip::m_sndLoop = loop;
	
	Vector3Copy(pos, DynamicSoundClip::m_sndPosition);
}

void DynamicSoundClip::SetVolume(float newVol)
{
	DynamicSoundClip::m_sndVolume = newVol;
}

void DynamicSoundClip::SetRadius(float newRad)
{
	DynamicSoundClip::m_sndRadius = newRad;
}

void DynamicSoundClip::SetPosition(vec3_t newPos)
{
	Vector3Copy(newPos, DynamicSoundClip::m_sndPosition);
}

void DynamicSoundClip::SetLoop(bool newLoop)
{
	DynamicSoundClip::m_sndLoop = newLoop;
}