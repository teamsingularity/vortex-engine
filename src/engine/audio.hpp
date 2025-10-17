#pragma once
#include <AL/al.h>
#include <AL/alc.h>
#include <vector>
#include "component/core/audiosource.hpp"
#include "component/core/camera.hpp"
#include <memory>

class VORTEXAPI Audio
{
public:
    Audio();
    ~Audio();


    static bool init();

    
    static void update();

    
    static void destroy();

   
   

private:
     static ALCdevice* device;
     static ALCcontext* context;

    

    Camera* camera = nullptr; 
};
