#pragma once

#include "SoundDevice.h"
#include "SoundBuffer.h"
#include "SoundSource.h"
#include "glm/vec2.hpp"
#include <thread>

#include <vector>
#include <string>

class AudioEngine
{
public:
	AudioEngine() = delete;
	~AudioEngine() = delete;

	static void playAudio(SoundSource* source, const std::string& name);
	static void stopAudio();

	static void setAudioPath(const std::string& path) { m_path = m_exePath + "/" + path.c_str(); }
	static void setExecutablePath(const std::string& executablePath);
	static void setAudioDevice();

	static void addSound(const std::string& name);

	static void unload();
	//static void LoadAudioSources();

private:
	static std::vector<SoundBuffer*> m_pSoundBuffers;
	static std::vector<std::pair<const std::string, ALuint>> m_pSounds;
	static std::string m_path;
	static std::string m_exePath;
	static SoundDevice* m_pSoundDevice;

	static std::thread audio_thread;
};


