#include "audiosource.hpp"
#include "camera.hpp"
#include "engine/engine.hpp"
#include "loader/OggLoader.hpp"
AudioSource::AudioSource()
{
}
AudioSource::~AudioSource()
{
}

void AudioSource::start()
{
    alGenSources(1, &source);
    alGenBuffers(1, &buffer);
}

void AudioSource::update()
{
    glm::vec3 pos = object->transform.position;
    alSource3f(source, AL_POSITION, pos.x, pos.y, pos.z);

}

void AudioSource::lateUpdate()
{
}

void AudioSource::destroy()
{
    alDeleteSources(1, &source);
}

void AudioSource::play()
{
    alSourcePlay(source);
}

void AudioSource::pause()
{
    alSourcePause(source);
}

void AudioSource::stop()
{
    alSourceStop(source);
}
void AudioSource::setBuffer(audio_t audio)
{
    ALenum format = (audio.channels == 1) ? AL_FORMAT_MONO16 : AL_FORMAT_STEREO16;
    alBufferData(buffer, format, audio.data.data(), static_cast<ALsizei>(audio.data.size()), audio.sampleRate);
    alSourcei(source, AL_BUFFER, buffer);

}