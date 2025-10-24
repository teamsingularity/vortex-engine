#ifndef TYPES_HPP
#define TYPES_HPP

#include <vector>

typedef struct
{
    int width;
    int height;
    unsigned char* data;
} image_t;

typedef struct 
{
    int sampleRate;
    int channels;
    std::vector<short> data;
} audio_t;

#endif //TYPES_HPP