#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define PLAY_GROUND "Playground"

// GamesWithGabe/Coding_Minecraft_ep.1_Challenge
// Challenge 01 : Create Entry for appication.
// Challenge 02 : Create window, start game loop.
// Challenge 03 : Add support for launching the game in different monitors
// Challenge 04 : Add way to launch the game in full screen
// Challenge 05 : Add event handlers for keyboard, mouse move, mouse scroll
//  * Challenge 05a : Add event handlers for game controllers if you have one. 

GLFWwindow* screenSetting(int width, int height, int monitor, int fullscreen)
{
    int size_m;
    GLFWmonitor** monitors = glfwGetMonitors(&size_m);
    return glfwCreateWindow(width, height, PLAY_GROUND, (!fullscreen) || (monitor >= size_m) ? NULL : monitors[monitor], NULL);
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    printf("%d %d\n", key, action);
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
    if(action == GLFW_PRESS)
    {
        double x, y;
        glfwGetCursorPos(window, &x, &y);
        printf("%lf %lf\n", x, y);
    }
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

    // setting screen
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

    while(!glfwWindowShouldClose(window))
    {
        glClearColor(1.0f, 0.3f, 0.4f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }
    
    glfwTerminate();
    return 0;
}