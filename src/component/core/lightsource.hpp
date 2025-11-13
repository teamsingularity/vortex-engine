#ifndef LIGHTSOURCE_HPP
#define LIGHTSOURCE_HPP
#include "../component.hpp"
#include "glm/glm.hpp"


class Lightsource : public Component {
public:
    Lightsource();
    void start();
    void update();
    void lateUpdate();
    void destroy();
    int type;
    glm::vec3 position;
    glm::vec3 direction;
    glm::vec3 color;
    float constant;
    float linear;
    float quadratic;
    float cutOff;
    float outerCutOff;
};

#endif