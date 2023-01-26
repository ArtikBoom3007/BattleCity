
#include "AudioEngine.h"

std::string  AudioEngine::m_path;
SoundDevice* AudioEngine::m_pSoundDevice;
std::vector<SoundBuffer*> AudioEngine::soundBuffers;

void AudioEngine::setAudioDevice() {
	m_pSoundDevice = SoundDevice::get();
}

//void AudioEngine::LoadAudioSources() {
//	SoundSource mySpeaker;
//	m_soundSources.push_back(std::make_pair(mySpeaker, glm::vec2(0)));
//}

void AudioEngine::playAudio(const std::string& name)
{
	SoundBuffer* soundBuffer = SoundBuffer::get();

	/*uint32_t*/ ALuint sound = soundBuffer->addSoundEffect((m_path + name + ".wav").c_str());
	
	soundBuffers.push_back(soundBuffer);

	SoundSource mySpeaker;

	if (name == "startScreen") {
		mySpeaker.setGain((float)0.030);
	}
	
	mySpeaker.Play(sound);
	
	mySpeaker.Update();

}

void AudioEngine::stopAudio() {
	SoundSource mySpeaker;
	mySpeaker.Stop();
}

void AudioEngine::unload() {
	stopAudio();
	//delete(m_pSoundDevice);
	//for (auto curBuf : soundBuffers) {
	//	for (int j = 0; j < curBuf->getBuffers().size(); j++) {
	//		//curBuf->removeSoundEffect(curBuf->getBuffers()[j]);
	//	}
	//}
}
