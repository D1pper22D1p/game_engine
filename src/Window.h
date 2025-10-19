#pragma once
#include <windows.h>
#include <string>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

class Window{
public:
    Window();
    ~Window();

    bool Initialize(int width, int height, const char* title);
    void Shutdown();

    HWND GetHWND() const { return m_hwnd; }
    int GetWidth() const { return m_width; }
    int GetHeight() const { return m_height; }

private:
    static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

    HWND m_hwnd;
    int m_width;
    int m_height;
    std::string m_title;
};