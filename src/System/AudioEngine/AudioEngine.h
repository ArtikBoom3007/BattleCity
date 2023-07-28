#pragma once

#include "SoundDevice.h"
#include "SoundBuffer.h"
#include "SoundSource.h"
#include "glm/vec2.hpp"
#include <vector>
#include <string>

class AudioEngine
{
public:
	AudioEngine() = delete;
	~AudioEngine() = delete;

	static void playAudio(const std::string& name);
	static void setAudioPath(const std::string& path) { m_path = path; }
	static void setAudioDevice();
	static void stopAudio();
	static void unload();
	//static void LoadAudioSources();

private:
	static std::vector<SoundBuffer*> m_pSoundBuffers;
	static std::vector<SoundSource*> m_pSoundSources;
	static std::string m_path;
	static SoundDevice* m_pSoundDevice;

};


