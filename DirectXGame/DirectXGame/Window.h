#pragma once
#include <Windows.h>

class Window
{
public:
    Window();
    bool init();
    /* Feed event OS messages into the window and dispatch them into the window procedure*/
    bool broadcast();
    bool release();
    bool isRun();

    // EVENTS. Use pure virtual/abstract functions, meaning inheriting class MUST implement them, except for onDestroy
    virtual void onCreate() = 0;
    virtual void onUpdate() = 0;
    virtual void onDestroy();

    ~Window();
protected:
    // Handle of the window, which is the output of CreateWindowEx
    HWND window_handle;
    bool window_is_run;
};
