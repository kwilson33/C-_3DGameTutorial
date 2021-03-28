#include "AppWindow.h"

int main() {
    AppWindow app;

    /* The game loop. While app is running, get messages from the OS and dispatch them */
    if (app.init()) {
        while (app.isRun()) {
            app.broadcast();
        }
    }

    return 0;
}