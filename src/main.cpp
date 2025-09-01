#include <GL/gl.h>

#include "graphics/Window.h"

using namespace Engine::Graphics;

int main() {
    Window window("Game", 800, 600);
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
    while (!window.closed())
    {
        window.clear();
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f( 0.5f, -0.5f);
        glVertex2f( 0.0f,  0.5f);
        glEnd();
        window.update();
    }
    return 0;
}