#pragma once
#include <AL/al.h>
#include <AL/alc.h>
#include <vector>
#include "component/core/audiosource.hpp"
#include "component/core/camera.hpp"
#include <memory>

/**
 * @class Audio
 * @brief Manages OpenAL audio device, context and listener for 3D audio.
 */
class VORTEXAPI Audio
{
public:

    /**
     * @brief Initializes OpenAL device and context.
     * @return True if initialization succeeded, false otherwise.
     */
    static bool init();

    /**
     * @brief Updates listener position and orientation based on the camera.
     */
    static void update();

    /**
     * @brief Destroys OpenAL context and device.
     */
    static void destroy();

private:
    /**
     * @brief OpenAL device pointer.
     */
    static ALCdevice* device;

    /**
     * @brief OpenAL context pointer.
     */
    static ALCcontext* context;

    /**
     * @brief Pointer to the current camera, used to update listener.
     */
    Camera* camera = nullptr;
};
