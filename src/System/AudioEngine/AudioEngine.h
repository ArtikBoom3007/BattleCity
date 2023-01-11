#pragma once

#include <vector>
#include <string>

class AudioEngine
{
public:
	AudioEngine() = delete;
	~AudioEngine() = delete;

	static void playAudio(const std::string& name);
	static void setAudioPath(const std::string& path) { m_path = path; }

private:
	static std::string m_path;
};


