#pragma once
#include <AL\alc.h>

class SoundDevice
{
public:
	SoundDevice();
	~SoundDevice() = delete;

	void deleteSoundDevice();
	static SoundDevice* get();

private:
	ALCdevice* p_ALCDevice;
	ALCcontext* p_ALCContext;


};

