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
	static void setAudioPath(const std::string& path) { m_path = m_exePath + "/" + path.c_str(); }
	static void setExecutablePath(const std::string& executablePath);
	static void setAudioDevice();
	static void stopAudio();
	static void unload();
	//static void LoadAudioSources();

private:
	static std::vector<SoundBuffer*> m_pSoundBuffers;
	static std::vector<SoundSource*> m_pSoundSources;
	static std::string m_path;
	static std::string m_exePath;
	static SoundDevice* m_pSoundDevice;

};


