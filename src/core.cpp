#include <stdio.h>
#include <math.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#ifndef RENDERABLE_H
#include "renderable.hpp"
#endif

#define PLAY_GROUND "Playground"

using namespace mathmetic;

// GamesWithGabe/Coding_Minecraft_ep.2_Challenge_1
// Challenge 01 : Draw a square on the screen using glDrawArrays.
// Challenge 02 : Draw a square on the screen using glDrawElements.
// Challenge 03 : Draw a star using glDrawElements.
// Challenge 04 : Draw the outline of a square using the GL_LINES primitive.


GLFWwindow* screenSetting(int width, int height, int monitor, int fullscreen)
{
    int size_m;
    GLFWmonitor** monitors = glfwGetMonitors(&size_m);
    return glfwCreateWindow(width, height, PLAY_GROUND, (!fullscreen) || (monitor >= size_m) ? NULL : monitors[monitor], NULL);
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    //printf("%d %d\n", key, action);
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
    // if(action == GLFW_PRESS)
    // {
    //     double x, y;
    //     glfwGetCursorPos(window, &x, &y);
    //     printf("%lf %lf\n", x, y);
    // }
}

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

    // screen setting
    {
        int width, height, monitor, fullscreen;
        printf("screen setting. width, height, monitor number, fullscreen :\n");
        scanf("%d %d %d %d", &width, &height, &monitor, &fullscreen);
        if (!(window = screenSetting(width, height, monitor, fullscreen)))
        {
            glfwTerminate();
            return -1;
        }
    }

    // key board & mouse Input
    glfwSetKeyCallback(window, keyCallback);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);

    glfwMakeContextCurrent(window);
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        return -1;
    }

    Shape shape_0, shape_1, shape_2;
    {
        // rect vertex with no indicies
        {
            std::vector<fvec3> rect{fvec3(0.5f, 0.5f), fvec3(-0.5f, 0.5f), fvec3(-0.5f, -0.5f),
                                fvec3(0.5f, 0.5f), fvec3(-0.5f, -0.5f), fvec3(0.5f, -0.5f)};
            std::vector<fvec3> rect_color(6, fvec3(0.2f, 0.8f, 0.3f));

            shape_0 = Shape(rect, rect_color);
        }

        // rect vertex with indicies
        {
            std::vector<fvec3> rect_2_color{fvec3(1.0f, 0.0f, 0.0f), fvec3(0.0f, 1.0f, 0.0f),
                                            fvec3(0.0f, 0.0f, 1.0f), fvec3(1.0f, 0.0f, 0.0f)};
            std::vector<fvec3> rect_2{fvec3(0.25f, 0.5f), fvec3(-0.25f, 0.5f),
                                      fvec3(-0.25f, -0.5f), fvec3(0.25f, -0.5f)};
            std::vector<ivec3> rect_2_ind{ivec3(0, 1, 2), ivec3(0, 2, 3)};
            std::vector<ivec2> outline_ind {ivec2(0, 1), ivec2(1, 2), ivec2(2, 3), ivec2(3, 0)};
            shape_1 = Shape(rect_2, rect_2_color, rect_2_ind);
            shape_1.SetOutLine(outline_ind);
        }

        // star vertex
        {
            const float pi = 3.1415926f;
            std::vector<fvec3> star;
            for(float deg = 18.0f; deg <= 360; deg += 72.0f)
            {
                star.push_back(fvec3(std::cos(deg * pi / 180.0f) * 0.75f, std::sin(deg * pi / 180.0f) * 0.75f));
            }

            float dist = 1.0f - 0.951057f * std::tan(36.0f * pi / 180.0f);
            for(float deg = 54.0f; deg <= 360; deg += 72.0f)
            {
                star.push_back(fvec3(std::cos(deg * pi / 180.0f) * dist, std::sin(deg * pi / 180.0f) * dist));
            }

            std::vector<ivec3> star_ind { ivec3(1, 6, 5), ivec3(6, 2, 7), ivec3(5, 6, 7), 
                                          ivec3(5, 7, 9), ivec3(0, 5, 9), ivec3(9, 7, 8),
                                          ivec3(7, 3, 8), ivec3(9, 8, 4)};

            std::vector<ivec2> outline_ind { ivec2(0, 5), ivec2(5, 1), ivec2(1, 6), ivec2(6, 2), ivec2(2, 7),
                                            ivec2(7, 3), ivec2(3, 8), ivec2(8, 4), ivec2(4, 9), ivec2(9, 0)};
            std::vector<fvec3> rect_color(10, fvec3(0.7f, 0.8f, 0.0f));
            shape_2 = Shape(star, rect_color, star_ind);
            shape_2.SetOutLine(outline_ind);
        }
    }

    Shader shader("shaders/vertex.glsl", "shaders/fragment.glsl");

    while(!glfwWindowShouldClose(window))
    {
        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shader.id);
        shape_0.Draw();
        shape_1.Draw();
        shape_2.Draw();

        glfwSwapBuffers(window);

        glfwPollEvents();
    }
    
    glfwTerminate();
    return 0;
}