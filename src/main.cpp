#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <engine/window.hpp>
#include <engine/input.hpp>
#include <engine/render/shader.hpp>
#include <engine/render/texture.hpp>
#include <loader/png.hpp>
#define WIDTH 1280
#define HEIGHT 720

int main(void){
    if (!window::init(WIDTH, HEIGHT, "Vortex Engine"))
    {
        std::cerr << "Failed to initialize window!" << std::endl; //Error struggles
        return 1;
    }

    input::init();

    // simple triangle
    GLfloat vertices[] = {
    //    x      y     z     u     v    
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
         0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
         0.0f,  0.5f, 0.0f, 0.5f, 1.0f
    };
    const char* vertexShaderSource = R"(
#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec2 uv;

out vec2 texCoord;

void main() {
    gl_Position = vec4(position, 1.0);
    texCoord = uv;
}
)";

const char* fragmentShaderSource = R"(
#version 330 core

out vec4 color;
in vec2 texCoord;

uniform sampler2D _texture;

void main() {
    color = texture(_texture, texCoord);
}
)";

    shader* shader = shader::loadShader(vertexShaderSource, fragmentShaderSource);

    image_t image = png_loader::load("res/image.png");
    texture* texture = texture::load(image);

    //VBO, VAO creation
    GLuint VAO, VBO;
    glGenVertexArrays(1, &VAO);     
    glGenBuffers(1, &VBO);       
    glBindVertexArray(VAO);          

    glBindBuffer(GL_ARRAY_BUFFER, VBO); 
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0); 

    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
    while (!window::shouldClose()) {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);

        if (input::getMouseButton(GLFW_MOUSE_BUTTON_1))
        {
            glClearColor(0.5f, 1.0f, 1.0f, 1.0f);
        }

        shader->use();
        texture->bind(0);     
        glBindVertexArray(VAO); 
        glDrawArrays(GL_TRIANGLES, 0, 3); 
        glBindVertexArray(0);

        window::swapBuffers();
    }

    glfwTerminate();
    return 0;
}