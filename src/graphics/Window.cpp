#include "Window.h"

#include <iostream>
#include <ostream>
#include <GLFW/glfw3.h>

namespace Engine::Graphics{
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

        void Window::update()
        {
            glfwPollEvents();
            glfwGetFramebufferSize(m_window, &m_width, &m_height);
            glfwSwapBuffers(m_window);
        }

        bool Window::closed() const
        {
            return glfwWindowShouldClose(m_window);
        }

        void Window::clear() const
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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
            glfwSetWindowSizeCallback(m_window,windowResize);
            return true;
        }

        void windowResize(GLFWwindow* window, int width, int height)
        {
            glViewport(0, 0, width, height);
        }
}
