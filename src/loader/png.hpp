#ifndef PNG_HPP
#define PNG_HPP

#include <string>
#include <util/types.hpp>
#include <defines.hpp>

/**
 * @file PNG.hpp
 * @brief Class for loading PNG images into engine's image_t format.
 */

/**
 * @class PNGLoader
 * @brief Utility class to load PNG images.
 *
 * This class provides a static method to read a PNG file and convert it
 * into the engine's internal `image_t` representation.
 */
class VORTEXAPI PNGLoader
{
public:
    /**
     * @brief Loads a PNG file.
     * @param filename Path to the PNG file to load.
     * @return image_t structure containing image data (RGBA8888) or nullptr if an error occurred.
     *
     * The returned `image_t` contains raw pixel data along with metadata such as
     * width, height, and channels. If loading fails, the pointer inside `image_t` is nullptr.
     */
    static image_t load(std::string filename);
};

#endif // PNG_HPP
