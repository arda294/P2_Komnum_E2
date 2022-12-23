#include <iostream>
#include "window.h"

// Contoh data : (1, 0.88889, 0.8, 0.72727, 0.66667, 0.61538, 0.57143, 0.53333, 0.50000) a = 0, b = 1

int main() {
        Window* window = new Window();
    bool running = true;
    while (running) {
        if (window->processMessages() == false) {
            running = false;
            break;
        }
    }
    return 0;
}
