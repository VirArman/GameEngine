#include "Window.h"

#include <iostream>
#include <ostream>
#include <GLFW/glfw3.h>

namespace Engine { namespace Graphics{
        Window::Window(const char* title, const int width, const int height):
                m_title(title), m_width(width), m_height(height), m_window(nullptr)
        {
            if (!init())
            {
                glfwTerminate();
            }
        }
        Window::~Window()
        {
            glfwDestroyWindow(m_window);
            glfwTerminate();
        }

        void Window::update() const
        {
            glfwPollEvents();
            glfwSwapBuffers(m_window);
        }

        bool Window::closed() const
        {
            return glfwWindowShouldClose(m_window);
        }

        bool Window::init()
        {
            if (!glfwInit())
            {
                std::cout << "Failed to initialize GLFW" << std::endl;
                return false;
            }
            m_window = glfwCreateWindow(m_width, m_height, m_title, nullptr, nullptr);
            if (!m_window)
            {
                std::cout << "Failed to create GLFW window" << std::endl;
                glfwTerminate();
            }
            glfwMakeContextCurrent(m_window);
            return true;
        }
    }
}