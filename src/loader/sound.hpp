#ifndef SOUND_HPP
#define SOUND_HPP

#include <component/component.hpp>
#include <vector>
#include <string>
#include <AL/al.h>

class Sound : public Component {
public:
    Sound();
    ~Sound();

    void start();              
    void play();                  
    void update();
    void lateUpdate();
    void destroy();               

    bool loadFromFile(const std::string& path); 

private:
    std::vector<short> samples;   
    int channels;
    int sampleRate;

    ALuint bufferID;
    ALuint sourceID;
};

#endif
