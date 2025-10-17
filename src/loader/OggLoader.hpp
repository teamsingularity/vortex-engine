#ifndef OGGLOADER_HPP
#define OGGLOADER_HPP
#include <vorbis/vorbisfile.h>
#include "util/types.hpp"
class OggLoader {
public:
    audio_t loadOgg(const char* filename);

};





#endif