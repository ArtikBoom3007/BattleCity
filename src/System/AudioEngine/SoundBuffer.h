#pragma once
#include <AL\al.h>
#include <vector>
class SoundBuffer
{
public:
	SoundBuffer();
	~SoundBuffer();

	std::vector<ALuint> getBuffers() { return p_SoundEffectBuffers;  }
	ALuint addSoundEffect(const char* filename);
	bool removeSoundEffect(const ALuint& buffer);

private:
	

	std::vector<ALuint> p_SoundEffectBuffers;
};

