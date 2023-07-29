
#include "AudioEngine.h"

std::string  AudioEngine::m_path;
std::string  AudioEngine::m_exePath;
SoundDevice* AudioEngine::m_pSoundDevice;
//std::vector<SoundSource*> AudioEngine::m_pSoundSources;
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

void AudioEngine::playAudio(const std::string& name)
{
	SoundBuffer* soundBuffer = new SoundBuffer();

	/*uint32_t*/ ALuint sound = soundBuffer->addSoundEffect((m_path + "/" + name + ".wav").c_str());
	
	m_pSoundBuffers.push_back(soundBuffer);

	SoundSource mySpeaker;

	if (name == "startScreen") {
		mySpeaker.setGain((float)0.030);
	}

	//m_pSoundSources.push_back(&mySpeaker);

	mySpeaker.Play(sound);
	
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
