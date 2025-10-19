#include "Window.h"
#include <stdexcept>

Window::Window() : m_hwnd(nullptr), m_width(0), m_height(0) {}

Window::~Window() {
    Shutdown();
}

bool Window::Initialize(int width, int height, const char* title) {
    m_width = width;
    m_height = height;
    m_title = title;

    HINSTANCE hInstance = GetModuleHandleW(nullptr);
    const wchar_t CLASS_NAME[] = L"GameEngine";

    WNDCLASSW wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hCursor = LoadCursorW(nullptr, MAKEINTRESOURCEW(32512));
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

    if(!RegisterClassW(&wc)){
        return false;
    }

    int ScreenX = (GetSystemMetrics(SM_CXSCREEN) - width) / 2;
    int ScreenY = (GetSystemMetrics(SM_CYSCREEN) - height) / 2;

    m_hwnd = CreateWindowExW(
        0,
        CLASS_NAME,
        std::wstring(m_title.begin(), m_title.end()).c_str(),
        WS_OVERLAPPEDWINDOW,
        ScreenX, ScreenY,
        width, height,
        nullptr,
        nullptr,
        hInstance,
        nullptr
    );

    if(!m_hwnd){
        return false;
    }

    ShowWindow(m_hwnd, SW_SHOW);
    return true;
}

void Window::Shutdown() {
    if(m_hwnd) {
        DestroyWindow(m_hwnd);
        m_hwnd = nullptr;
    }
}

LRESULT CALLBACK Window::WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
    switch (msg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    case WM_CLOSE:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProcW(hwnd, msg, wparam, lparam);
}