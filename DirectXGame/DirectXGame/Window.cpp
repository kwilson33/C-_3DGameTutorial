#include "Window.h"

Window* window = nullptr;

Window::Window()
{
}

// L = long. W = word
/* Callback means that this is a callable accepted by a class or function, used to customize the current logic depending on that callback. This function returns a callback function
*/
LRESULT CALLBACK window_procedure(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
    switch (msg) {
    case WM_CREATE:
        /* Event fired when window is created. Execute the onCreate() function and return NULL*/
        window->onCreate();
        break;
    case WM_DESTROY:
        /* Event fired when window is destroyed.
        Execute the onDestroy() function, tell OS that window wants to terminate,
        and return NULL*/
        window->onDestroy();
        ::PostQuitMessage(0);
        break;
    default:
        // When we receive message we are not handling, call this.
        return ::DefWindowProc(hwnd, msg, wparam, lparam);
    }

    return NULL;
}
bool Window::init()
{
    // Step 1) Define the properties and appearance of window and register the Window class
    WNDCLASSEX wc;
    wc.cbClsExtra = NULL;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.cbWndExtra = NULL;
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wc.hInstance = NULL;
    // To get a normal C literal string to assign to a LPCWSTR, you need to prefix it with L
    wc.lpszClassName = L"MyWindowClass";
    wc.lpszMenuName = L"";
    wc.style = NULL;
    // Most important attribute. Defines how we interact with window
    wc.lpfnWndProc = window_procedure;

    // If the registration of the class fails, return false
    if (!::RegisterClassEx(&wc)) {
        return false;
    }

    // Set pointer as address of the window object
    if (!window) {
        window = this;
    }

    // Step 2) Create the window and save its handle
    window_handle = ::CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, L"MyWindowClass", L"DirectX Application", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1024, 768, NULL, NULL, NULL, NULL);

    // If creation fails...
    if (!window_handle) {
        return false;
    }

    // Show the window!
    ::ShowWindow(window_handle, SW_SHOW);
    // Redraw content of window
    ::UpdateWindow(window_handle);

    // Set flag to indicate window is initialized and running
    window_is_run = true;

    return true;
}

bool Window::release()
{
    // Destroy the window
    if (!::DestroyWindow(window_handle)) {
        return false;
    }
}

bool Window::isRun()
{
    return window_is_run;
}

bool Window::broadcast()
{
    MSG msg;

    // Get message from the queue of OS messages until that queue is empty
    while (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) > 0) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }

    window->onUpdate();

    // Allow minimal pause so CPU can handle loop in a relaxed way
    Sleep(0);

    return true;
}

void Window::onDestroy()
{
    // Set flag to indicate window is initialized and running
    window_is_run = false;
}

Window::~Window()
{
}