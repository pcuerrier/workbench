#include "GLFW/glfw3.h"

#include <cstdio>

int main(int argc, char** argv)
{
    if (!glfwInit())
    {
        fprintf(stderr, "GLFW initialization failed!\n");
        return 1;
    }
    return 0;
}