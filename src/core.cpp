#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main()
{
    printf("Hello. Good Day. :)\n");
    glfwInit();

    GLFWwindow* window = glfwCreateWindow(800, 600, "Play Gound", NULL, NULL);

    glfwMakeContextCurrent(window);
    while (true)
    {
    }
    

    puts("exit");

    return 0;
}