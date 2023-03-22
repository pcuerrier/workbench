#include "MainProgram.hpp"

// GLAD must be included before GLFW3
#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#include <cstdio>

namespace {

void error_callback(int code, const char* description)
{
    fprintf(stderr, "GLFW failed with code %d : %s\n", code, description);
}

void monitor_callback(GLFWmonitor* monitor, int event)
{
    if (event == GLFW_CONNECTED)
    {
        // The monitor was connected
        // TODO: Display monitor information?
        fprintf(stderr, "A monitor was connected.\n");
    }
    else if (event == GLFW_DISCONNECTED)
    {
        // The monitor was disconnected
        // TODO: Display monitor information?
        // TODO: Replace primary monitor?
        fprintf(stderr, "A monitor was disconnected.\n");
    }
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
    else if (key == GLFW_KEY_C && action == GLFW_PRESS)
    {
        static bool full = false;
        static bool initialized = false;
        static GLFWmonitor* monitor = glfwGetPrimaryMonitor();
        static const GLFWvidmode* mode = glfwGetVideoMode(monitor);

        if (!initialized)
        {
            glfwWindowHint(GLFW_RED_BITS, mode->redBits);
            glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
            glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
            glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
        }
        full = !full;
        if (full)
            glfwSetWindowMonitor(window, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
        else
            glfwSetWindowMonitor(window, NULL, 0, 0, 640, 480, mode->refreshRate);
    }

}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

} // ::anonymous::namespace

int MainProgram::Run()
{
    /* Initialize the library */
    if (!glfwInit())
    {
        fprintf(stderr, "GLFW initialization failed!\n");
        return -1;
    }

    glfwSetErrorCallback(error_callback);
    glfwSetMonitorCallback(monitor_callback);

    // TODO: Review GLFW window creation hints
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    /* Create a windowed mode window and its OpenGL context */
    m_window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!m_window)
    {
        fprintf(stderr, "GLFW Window creation failed!\n");
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(m_window);

    /* Load OpenGL functions pointers */
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        fprintf(stderr, "GLAD OpenGL Functions loading failed!\n");
        return -1;
    }  

    // TODO: To be revised
    glfwSwapInterval(1);

    glfwSetKeyCallback(m_window, key_callback);
    glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(m_window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(m_window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}