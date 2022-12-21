#include <iostream>
#include "window.h"


int main() {
    /*Data data = {1, 0.88889, 0.8, 0.72727, 0.66667, 0.61538, 0.57143, 0.53333, 0.50000};
    std::cout << Trapezoid::calc(8, data, 0, 1) << "\n";
    std::cout << Romberg::calc(data, 0, 1);*/

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
