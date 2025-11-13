#include "lightsource.hpp"
#include "engine/engine.hpp"



void Lightsource::start()
{
Engine::scene->addLightsource(this);
}

void Lightsource::update()
{

}

void Lightsource::lateUpdate()
{

}

void Lightsource::destroy()
{

}