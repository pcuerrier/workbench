#pragma once

class GLFWwindow;
typedef GLFWwindow GLFWWwindow;

class MainProgram
{
public:
    MainProgram()  = default;
    ~MainProgram() = default;

    int Run();

private:
    GLFWwindow*  m_window;
};
