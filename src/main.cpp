#include "graphics/Window.h"

using namespace Engine::Graphics;

int main() {
    Window window("Game", 800, 600);
    while (!window.closed())
    {
        window.update();
    }
    return 0;
}