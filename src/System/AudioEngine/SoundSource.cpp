#include "SoundSource.h"

SoundSource::SoundSource()
{
	alGenSources(1, &m_pSource);
	alSourcef(m_pSource, AL_PITCH, p_Pitch);
	alSourcef(m_pSource, AL_GAIN, p_Gain);
	//alSourcei(m_pSource, AL_SOURCE_RELATIVE, AL_FALSE);
	alSource3f(m_pSource, AL_POSITION, p_Position[0], p_Position[1], p_Position[2]);
	alSource3f(m_pSource, AL_VELOCITY, p_Velocity[0], p_Velocity[1], p_Velocity[2]);
	alSourcei(m_pSource, AL_LOOPING, p_LoopSound);
	alSourcei(m_pSource, AL_BUFFER, p_Buffer);
}

SoundSource::~SoundSource()
{
	alDeleteSources(1, &m_pSource);
}

void SoundSource::Play(const ALuint buffer_to_play)
{
	
	if (buffer_to_play != p_Buffer)
	{
			alSourceQueueBuffers(m_pSource, 1, &buffer_to_play);
			p_Buffer = buffer_to_play;
			alSourcei(m_pSource, AL_BUFFER, (ALint)p_Buffer);
	}

	alSourcePlay(m_pSource);


	ALint state = AL_PLAYING;
	while (state == AL_PLAYING && alGetError() == AL_NO_ERROR)
	{
		alGetSourcei(m_pSource, AL_SOURCE_STATE, &state);
	}


}

void SoundSource::setGain(float gain) {
	p_Gain = gain;
	alSourcef(m_pSource, AL_GAIN, p_Gain);
}

void SoundSource::Close() {
	alSourceStop(m_pSource);
	if (alIsSource(m_pSource)) alDeleteSources(1, &m_pSource);
}

void SoundSource::Stop() {
	alSourceStop(m_pSource);
}

void SoundSource::Move(float X, float Y, float Z) {
	p_Position[0] = X;
	p_Position[1] = Y;
	p_Position[2] = Z;
	alSourcefv(m_pSource, AL_POSITION, p_Position);
}

void SoundSource::Update() {
	int      Processed = 0;
	ALuint      BufID;

	// Получаем количество отработанных буферов
	alGetSourcei(m_pSource, AL_BUFFERS_PROCESSED, &Processed);

	// Если таковые существуют то
	while (Processed-- > 0)
	{
		// Исключаем их из очереди
		alSourceUnqueueBuffers(m_pSource, 1, &BufID);
	}
}