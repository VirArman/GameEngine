#pragma once
#ifndef GAMEENGINE_WINDOW_H
#define GAMEENGINE_WINDOW_H


struct GLFWwindow;

namespace Engine { namespace Graphics{
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
            void update() const;
            bool closed() const;
        private:
            bool init();
        };
    }
}
#endif //GAMEENGINE_WINDOW_H