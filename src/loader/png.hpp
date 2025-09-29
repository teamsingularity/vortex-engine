#ifndef PNG_HPP
#define PNG_HPP

#include <string>
#include <util/types.hpp>

class png_loader
{
public:
    /* Loads an PNG image and returns image info struct with pointer to RGBA8888 raw data, nullptr if error occured */
    static image_t load(std::string filename);
};

#endif //PNG_HPP