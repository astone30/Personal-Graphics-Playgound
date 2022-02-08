#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define PLAY_GROUND "Playground"

int main()
{
    GLFWwindow* window;
    if(!glfwInit())
    {
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(800, 600, PLAY_GROUND, NULL, NULL);
    if(!window)
    {
        glfwTerminate();
        return -1;   
    }

    glfwMakeContextCurrent(window);
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        return -1;
    }

    while(!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }
    
    glfwTerminate();
    return 0;
}