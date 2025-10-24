#include "audiosource.hpp"
#include <component/component.hpp>
#include <object/gameobject.hpp>
#include <iostream>

AudioSource::AudioSource()
{
}
AudioSource::~AudioSource()
{
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

void AudioSource::start()
{
    alGenSources(1, &source);
    alGenBuffers(1, &buffer);

    std::cout << buffer << std::endl;
    
    // Set default source properties
    // alSourcef(source, AL_PITCH, 1.0f);
    // alSourcef(source, AL_GAIN, 1.0f);
    // alSource3f(source, AL_POSITION, 0, 0, 0);
    // alSource3f(source, AL_VELOCITY, 0, 0, 0);
    // alSourcei(source, AL_LOOPING, AL_FALSE);
}

void AudioSource::setBuffer(audio_t audio)
{
    ALint state;
    alGetSourcei(source, AL_SOURCE_STATE, &state);
    if (state == AL_PLAYING) {
        alSourceStop(source);
    }

    // Determine format
    ALenum format;
    if (audio.channels == 1) {
        format = AL_FORMAT_MONO16;
    } else if (audio.channels == 2) {
        format = AL_FORMAT_STEREO16;
    } else {
        std::cout << "Unsupported audio format: " << audio.channels << " channels" << std::endl;
        return;
    }

    if (audio.data.empty()) {
        std::cout << "Invalid audio data" << std::endl;
        return;
    }
    
    alBufferData(buffer, format, audio.data.data(), audio.data.size() * sizeof(short), audio.sampleRate);
    ALenum error = alGetError();
    if (error != AL_NO_ERROR) {
        std::cout << "OpenAL buffer error: " << error << std::endl;
        return;
    }
    
    alSourcei(source, AL_BUFFER, buffer);
    error = alGetError();
    if (error != AL_NO_ERROR) {
        std::cout << "OpenAL source error: " << error << std::endl;
    }
}