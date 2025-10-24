#include <vorbis/vorbisfile.h>
#include <AL/al.h>
#include <AL/alc.h>
#include <vector>
#include <iostream>
#include "oggloader.hpp"

audio_t OggLoader::load(const char* filename)
{
    audio_t audio = {};
    FILE* file = fopen(filename, "rb");
    if (!file) {
        std::cerr << "Failed to open OGG file: " << filename << std::endl;
        return audio;
    }

    OggVorbis_File vf;
    if (ov_open(file, &vf, nullptr, 0) < 0) {
        std::cerr << "Failed to decode OGG file: " << filename << std::endl;
        fclose(file);
        return audio;
    }

    vorbis_info* vi = ov_info(&vf, -1);
    audio.sampleRate = vi->rate;
    audio.channels = vi->channels;

    std::vector<short> pcm;
    char buffer[4096];
    int bitstream;
    long bytes;

    while ((bytes = ov_read(&vf, buffer, sizeof(buffer), 0, 2, 1, &bitstream)) > 0) {
        short* samples = reinterpret_cast<short*>(buffer);
        pcm.insert(pcm.end(), samples, samples + (bytes / 2));
    }

    ov_clear(&vf);

    audio.data = pcm;

    return audio;
}
