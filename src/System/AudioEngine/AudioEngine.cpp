
#include "AudioEngine.h"
#include <algorithm>

std::string  AudioEngine::m_path;
std::string  AudioEngine::m_exePath;
SoundDevice* AudioEngine::m_pSoundDevice;
std::vector<std::pair<const std::string, ALuint>> AudioEngine::m_pSounds;
std::vector<SoundBuffer*> AudioEngine::m_pSoundBuffers;

void AudioEngine::setAudioDevice() {
	m_pSoundDevice = SoundDevice::get();
}

void AudioEngine::setExecutablePath(const std::string& executablePath) {
	size_t found = executablePath.find_last_of("/\\");
	m_exePath = executablePath.substr(0, found);
}

//void AudioEngine::LoadAudioSources() {
//	SoundSource mySpeaker;
//	m_soundSources.push_back(std::make_pair(mySpeaker, glm::vec2(0)));
//}

void AudioEngine::addSound(const std::string& name) {

	SoundBuffer* soundBuffer = new SoundBuffer();

	/*uint32_t*/ ALuint sound = soundBuffer->addSoundEffect((m_path + "/" + name.c_str() + ".wav").c_str());

	m_pSoundBuffers.push_back(soundBuffer);

	m_pSounds.push_back(std::make_pair(name, sound));

}

void AudioEngine::playAudio(const std::string& name)
{

	SoundSource mySpeaker;

	if (name == "start_screen_audio") {
		mySpeaker.setGain((float)0.030);
	}

	for (auto& currentSound : m_pSounds) {
		if (currentSound.first == name) {
			mySpeaker.Play(currentSound.second);
			break;
		}
	}

	//m_pSoundSources.push_back(&mySpeaker);

	//mySpeaker.Play(itr->second);

	mySpeaker.Update();



}

void AudioEngine::stopAudio() {
	//for (int i = 0; i < m_pSoundSources.size(); i++) {
		//m_pSoundSources[i]->Stop();
	//}
}

void AudioEngine::unload() {
	stopAudio();
	for (auto& buffer : m_pSoundBuffers) {
		delete(buffer);
	}
	m_pSoundDevice->deleteSoundDevice();
	//delete(m_pSoundDevice);
	//for (auto curBuf : soundBuffers) {
	//	for (int j = 0; j < curBuf->getBuffers().size(); j++) {
	//		//curBuf->removeSoundEffect(curBuf->getBuffers()[j]);
	//	}
	//}
}
