#pragma once
#include <memory>
#include "Window.h"
#include "Renderer.h"
#include "InputManager.h"

class Engine {
public:
    Engine();
    ~Engine();

    bool Initialize(int width, int height, const char* title);
    void Run();
    void Shutdown();

private:
    bool HandleMessages();

    std::unique_ptr<Window> m_window;
    std::unique_ptr<Renderer> m_renderer;
    std::unique_ptr<InputManager> m_inputManager;
    bool m_isRunning;
};