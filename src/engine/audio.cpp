#include <AL/al.h>
#include "audio.hpp"
#include "engine.hpp"

bool Audio::init()
{
    device = alcOpenDevice(nullptr); 
    if (!device) return false;

    context = alcCreateContext(device, nullptr);
    if (!context) return false;

    alcMakeContextCurrent(context);

    return true;

}

void Audio::destroy()
{
    if (context)
    {
        alcMakeContextCurrent(nullptr);
        alcDestroyContext(context);
        context = nullptr;
    }
    
    if (device)
    {
        alcCloseDevice(device);
        device = nullptr;
    }
}

void Audio::update()
{
    glm::vec3 pos;
    glm::vec3 forward;
    glm::vec3 up;

    if (Engine::scene->camera && Engine::scene->camera->object) 
    {
        pos     = Engine::scene->camera->object->transform.position;
        forward = Engine::scene->camera->object->transform.forward;
        up      = Engine::scene->camera->object->transform.up;
    }

    alListener3f(AL_POSITION, pos.x, pos.y, pos.z);

    float ori[6] = { forward.x, forward.y, forward.z, up.x, up.y, up.z };
    alListenerfv(AL_ORIENTATION, ori);
}


ALCdevice* Audio::device = nullptr;
ALCcontext* Audio::context = nullptr;
