#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <Window.hpp>
#include "shader.hpp"
#define WIDTH 1280
#define HEIGHT 720

int main(void){
    


    if (!Window::init(WIDTH, HEIGHT, "Vortex Engine"))
    {
        std::cerr << "Failed to initialize window!" << std::endl; //Error struggles
        return 1;
    }

    //Testing triangle n shader (tnx GPT)
       GLfloat vertices[] = {
        -0.5f, -0.5f, 0.0f,  // левая нижняя
         0.5f, -0.5f, 0.0f,  // правая нижняя
         0.0f,  0.5f, 0.0f   // верхняя
    };
    const char* vertexShaderSource = R"(
#version 330 core
layout (location = 0) in vec3 position;
void main() {
    gl_Position = vec4(position, 1.0);
}
)";

const char* fragmentShaderSource = R"(
#version 330 core
out vec4 color;
void main() {
    color = vec4(0.5f, 0.0f, 0.5f, 1.0f); // желтый
}
)";

Shader shader(vertexShaderSource, fragmentShaderSource);

    //VBO, VAO creation
    GLuint VAO, VBO;
    glGenVertexArrays(1, &VAO);     
    glGenBuffers(1, &VBO);       
    glBindVertexArray(VAO);          

    glBindBuffer(GL_ARRAY_BUFFER, VBO); 
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0); 

    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
    while (!Window::shouldClose()) //Main loop
    {
    glfwPollEvents();
    glClear(GL_COLOR_BUFFER_BIT);

    shader.use();          
    glBindVertexArray(VAO); 
    glDrawArrays(GL_TRIANGLES, 0, 3); 
    glBindVertexArray(0);

    Window::swapBuffers();
    }

    glfwTerminate();
    return 0;
}