#pragma once
#ifndef GAMEENGINE_WINDOW_H
#define GAMEENGINE_WINDOW_H


struct GLFWwindow;
namespace Engine::Graphics{
        void windowResize(GLFWwindow* window, int width, int height);
        class Window
        {
        private:
            const char* m_title;
            int m_width, m_height;
            GLFWwindow* m_window;
            bool bclosed = false;
        public:
            Window(const char* title, int width, int height);
            ~Window();
            void update();
            [[nodiscard]] bool closed() const;
            void clear() const;
            [[nodiscard]] inline int getWidth() const { return m_width; }
            [[nodiscard]] inline int getHeight() const { return m_height; }
        private:
            bool init();
        };
    }

#endif //GAMEENGINE_WINDOW_H