
#include "AudioEngine.h"
#include <ctime>
#include <iostream>

std::string AudioEngine::m_path;
SoundDevice* AudioEngine::m_pSoundDevice;

void AudioEngine::setAudioDevice() {
	SoundDevice* mysounddevice = SoundDevice::get();
	m_pSoundDevice = mysounddevice;
}

void AudioEngine::playAudio(const std::string& name)
{

	unsigned int begin2 = clock();

	uint32_t /*ALuint*/ sound = SoundBuffer::get()->addSoundEffect((m_path + name + ".wav").c_str());

	unsigned int beg3 = clock();

	SoundSource mySpeaker;
	
	mySpeaker.Play(sound);

	unsigned int end = clock();
	std::cout << beg3 - begin2 << " add effect " << std::endl;
	std::cout << end - beg3 << " play " << std::endl;


}