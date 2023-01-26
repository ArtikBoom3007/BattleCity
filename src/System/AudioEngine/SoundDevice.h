#pragma once
#include <AL\alc.h>

class SoundDevice
{
public:
	SoundDevice();
	~SoundDevice();
	static SoundDevice* get();

private:
	ALCdevice* p_ALCDevice;
	ALCcontext* p_ALCContext;


};

