
#include "AudioEngine.h"

bool AudioEngine::m_shouldPlay = true;
std::string  AudioEngine::m_path;
SoundDevice* AudioEngine::m_pSoundDevice;

void AudioEngine::setAudioDevice() {
	SoundDevice* mysounddevice = SoundDevice::get();
	m_pSoundDevice = mysounddevice;
}

//void AudioEngine::LoadAudioSources() {
//	SoundSource mySpeaker;
//	m_soundSources.push_back(std::make_pair(mySpeaker, glm::vec2(0)));
//}

void AudioEngine::playAudio(const std::string& name)
{
	
	/*uint32_t*/ ALuint sound = SoundBuffer::get()->addSoundEffect((m_path + name + ".wav").c_str());
	
	SoundSource mySpeaker;

	if (name == "startScreen") {
		mySpeaker.setGain((float)0.015);
	}
	
	mySpeaker.Play(sound);
	
	mySpeaker.Update();

}

void AudioEngine::stopAudio() {
	SoundSource mySpeaker;
	mySpeaker.Stop();
}

