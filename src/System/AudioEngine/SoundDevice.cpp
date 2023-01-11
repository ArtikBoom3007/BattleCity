#include "SoundDevice.h"
#include <AL\al.h>
#include <iostream>

SoundDevice* SoundDevice::get()
{
	static SoundDevice* snd_device = new SoundDevice();
	return snd_device;
}

SoundDevice::SoundDevice()
{
	p_ALCDevice = alcOpenDevice(nullptr); // nullptr = get default device
	if (!p_ALCDevice)
		std::cerr << "failed to get sound device" << std::endl;

	p_ALCContext = alcCreateContext(p_ALCDevice, nullptr);  // create context
	if(!p_ALCContext)
		std::cerr << "Failed to set sound context" << std::endl;

	if (!alcMakeContextCurrent(p_ALCContext))   // make context current
		std::cerr << "failed to make context current " << std::endl;

	const ALCchar* name = nullptr;
	if (alcIsExtensionPresent(p_ALCDevice, "ALC_ENUMERATE_ALL_EXT"))
		name = alcGetString(p_ALCDevice, ALC_ALL_DEVICES_SPECIFIER);
	if (!name || alcGetError(p_ALCDevice) != AL_NO_ERROR)
		name = alcGetString(p_ALCDevice, ALC_DEVICE_SPECIFIER);
	std::cout << "Opened " << name << std::endl;
}

SoundDevice::~SoundDevice()
{
	if (!alcMakeContextCurrent(nullptr))
		std::cerr << "failed to set context to nullptr " << std::endl;

	alcDestroyContext(p_ALCContext);
	if (p_ALCContext)
		std::cerr << "failed to unset during close " << std::endl;

	if (!alcCloseDevice(p_ALCDevice))
		std::cerr << "failed to close sound device " << std::endl;
}
