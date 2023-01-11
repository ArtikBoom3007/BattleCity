#include "SoundDevice.h"
#include "SoundBuffer.h"
#include "SoundSource.h"
#include "AudioEngine.h"

std::string AudioEngine::m_path;

void AudioEngine::playAudio(const std::string& name)
{
	SoundDevice* mysounddevice = SoundDevice::get();

	/*uint32_t*/ ALuint sound = SoundBuffer::get()->addSoundEffect((m_path + name + ".ogg").c_str());

	SoundSource mySpeaker;

	mySpeaker.Play(sound);


}