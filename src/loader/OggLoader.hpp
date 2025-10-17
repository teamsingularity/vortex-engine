#ifndef OGGLOADER_HPP
#define OGGLOADER_HPP

#include <vorbis/vorbisfile.h>
#include "util/types.hpp"

/**
 * @file OggLoader.hpp
 * @brief Class for loading OGG audio files into audio_t structures.
 */

/**
 * @class OggLoader
 * @brief Utility class to load audio data from OGG files.
 *
 * This class provides a method to read an OGG file and convert it into
 * the engine's internal audio representation (`audio_t`), storing
 * audio samples and metadata like sample rate and channels.
 */
class OggLoader {
public:
    /**
     * @brief Loads an OGG file.
     * @param filename Path to the OGG file to load.
     * @return audio_t structure containing the audio data.
     *
     * Reads the OGG file, decodes it, and fills the audio_t structure
     * with PCM data, sample rate, and channel information.
     */
    audio_t loadOgg(const char* filename);
};

#endif // OGGLOADER_HPP
