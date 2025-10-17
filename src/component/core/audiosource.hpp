#ifndef AUDIOSOURCE_HPP
#define AUDIOSOURCE_HPP

#include <component/component.hpp>
#include <glm/glm.hpp>
#include <AL/al.h>
#include "util/types.hpp"

/**
 * @class AudioSource
 * @brief Component responsible for playing 3D audio in the scene.
 *
 * The AudioSource component manages OpenAL audio playback for a GameObject.
 * It allows playing, pausing, and stopping audio buffers, as well as assigning
 * specific audio data to be played through this source.
 *
 * Each AudioSource corresponds to one OpenAL source handle (`ALuint source`).
 */
class AudioSource : public Component
{
public:
    /**
     * @brief Constructs a new AudioSource component.
     *
     * Initializes the OpenAL source handle and prepares it for use.
     */
    AudioSource();

    /**
     * @brief Destructor.
     *
     * Releases the OpenAL source and any assigned buffers.
     */
    ~AudioSource();

    /**
     * @brief Called once when the component is initialized.
     *
     * Typically used to set initial audio parameters or register
     * the source with the engine’s audio system.
     */
    void start();

    /**
     * @brief Called every frame before rendering.
     *
     * Can be used to update audio properties such as position.
     */
    void update();

    /**
     * @brief Called after all updates are processed.
     *
     * Useful for synchronizing audio with game logic that runs later in the frame.
     */
    void lateUpdate();

    /**
     * @brief Called when the component is destroyed.
     *
     * Stops playback and deletes the OpenAL source.
     */
    void destroy();

    /**
     * @brief Starts audio playback.
     *
     * Plays the assigned audio buffer from the current position.
     */
    void play();

    /**
     * @brief Pauses currently playing audio.
     *
     * Audio can be resumed later using `play()`.
     */
    void pause();

    /**
     * @brief Stops audio playback.
     *
     * Resets playback position to the beginning of the buffer.
     */
    void stop();

    /**
     * @brief Assigns an audio buffer to this source.
     *
     * @param audio Audio buffer handle (`audio_t`) to be played by this source.
     */
    void setBuffer(audio_t audio);

    /**
     * @brief OpenAL source handle.
     *
     * Identifies this particular sound emitter in the OpenAL context.
     */
    ALuint source;

    /**
     * @brief Currently assigned audio buffer.
     *
     * This buffer contains the audio data that will be played by the source.
     */
    ALuint buffer;
};

#endif // AUDIOSOURCE_HPP
