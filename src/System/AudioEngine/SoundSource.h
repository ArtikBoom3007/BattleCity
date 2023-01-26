#pragma once
#include <AL\al.h>
class SoundSource
{
public:
	SoundSource();
	~SoundSource();

	void Play(const ALuint buffer_to_play);
	//bool IsStreamed();
	void Close();
	void Update();
	void Move(float X, float Y, float Z);
	void Stop();
	void setGain(float gain);

private:
	ALuint m_pSource;
	float p_Pitch = 1.f;
	float p_Gain = 1.f;
	float p_Position[3] = { 0,0,0 };
	float p_Velocity[3] = { 0,0,0 };
	bool p_LoopSound = false;
	ALuint p_Buffer = 0;
};

