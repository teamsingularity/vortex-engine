#include "sound.hpp"
#include <iostream>
#include <AL/al.h>
#include <AL/alc.h>
#include <nogg/ogg.h> 
#include <vector>
#include <string>

Sound::Sound()
    : channels(0), sampleRate(0), bufferID(0), sourceID(0) 
{
}

Sound::~Sound() 
{
    if (sourceID) alDeleteSources(1, &sourceID);
    if (bufferID) alDeleteBuffers(1, &bufferID);
}


bool Sound::loadFromFile(const std::string& path) 
{
    FILE* f = fopen(path.c_str(), "rb");
    if (!f) {
        std::cerr << "Failed to open OGG file: " << path << std::endl;
        return false;
    }

    OggVorbis_File vf;
    if (ov_open(f, &vf, nullptr, 0) < 0) {
        std::cerr << "Failed to init OGG stream" << std::endl;
        fclose(f);
        return false;
    }

    vorbis_info* vi = ov_info(&vf, -1);
    channels = vi->channels;
    sampleRate = vi->rate;

    
    const int tempSize = 4096;
    short pcm[tempSize];
    int bitstream;
    long ret;

    samples.clear();
    while ((ret = ov_read(&vf, reinterpret_cast<char*>(pcm), sizeof(pcm), 0, 2, 1, &bitstream)) > 0) {
        samples.insert(samples.end(), pcm, pcm + ret / 2);
    }

    ov_clear(&vf);

    std::cout << "✅ OGG loaded: " << path 
              << " | Channels: " << channels 
              << " | SampleRate: " << sampleRate 
              << " | Samples: " << samples.size() << std::endl;

    return true;
}


void Sound::start() 
{
    if (samples.empty()) {
        std::cerr << "No samples loaded!" << std::endl;
        return;
    }

    alGenBuffers(1, &bufferID);
    alBufferData(bufferID,
                 channels == 2 ? AL_FORMAT_STEREO16 : AL_FORMAT_MONO16,
                 samples.data(),
                 static_cast<ALsizei>(samples.size() * sizeof(short)),
                 sampleRate);

    alGenSources(1, &sourceID);
    alSourcei(sourceID, AL_BUFFER, bufferID);
}

void Sound::play()
{
    if (sourceID)
        alSourcePlay(sourceID);
}

void Sound::update() {}
void Sound::lateUpdate() {}
void Sound::destroy() 
{
    if (sourceID) {
        alSourceStop(sourceID);
        alDeleteSources(1, &sourceID);
        sourceID = 0;
    }
    if (bufferID) {
        alDeleteBuffers(1, &bufferID);
        bufferID = 0;
    }
    samples.clear();
}
