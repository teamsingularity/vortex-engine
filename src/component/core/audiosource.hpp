#ifndef AUDIOSOURCE_HPP
#define AUDIOSOURCE_HPP

#include <component/component.hpp>
#include <glm/glm.hpp>
#include <AL/al.h>
#include "util/types.hpp"
class AudioSource : public Component
{
public:
    AudioSource();
    ~AudioSource();

    void start();
    void update();
    void lateUpdate();
    void destroy();
    void play();
    void pause();
    void stop();
    void setBuffer(audio_t audio);
    ALuint source;
    ALuint buffer;
};

#endif 