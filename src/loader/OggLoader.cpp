#include <vorbis/vorbisfile.h>
#include <AL/al.h>
#include <AL/alc.h>
#include <vector>
#include "OggLoader.hpp"

audio_t OggLoader::loadOgg(const char* filename)
{
    audio_t audio;
    OggVorbis_File vf;
    if (ov_fopen(filename, &vf) < 0)
        return audio;

    vorbis_info* info = ov_info(&vf, -1);

    std::vector<char> data;
    char temp[4096];
    int bitstream;
    long bytes;
    do {
        bytes = ov_read(&vf, temp, sizeof(temp), 0, 2, 1, &bitstream);
        if (bytes > 0)
            data.insert(data.end(), temp, temp + bytes);
    } while (bytes > 0);
    audio.sampleRate = info->rate;

    audio.channels = info->channels;

    audio.data = std::move(data);
    ov_clear(&vf);
    return audio;
}