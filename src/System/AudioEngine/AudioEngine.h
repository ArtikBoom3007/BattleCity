#pragma once

#include "SoundDevice.h"
#include "SoundBuffer.h"
#include "SoundSource.h"
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

private:
	static std::string m_path;
	static SoundDevice* m_pSoundDevice;

};


