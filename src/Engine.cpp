#include "Engine.h"
#include <iostream>

Engine::Engine() : m_isRunning(false) {}

Engine::~Engine() {
    Shutdown();
}

bool Engine::Initialize(int width, int height, const char* title){
    try
    {
        m_window = std::make_unique<Window>();
        if(!m_window->Initialize(width, height, title)) {
            std::cerr << "Failed to initialize window\n";
            return false;
        }

        m_renderer = std::make_unique<Renderer>();
        if(!m_renderer->Initialize(m_window->GetHWND(), width, height)){
            std::cerr << "Failed to initialize renderer\n";
            return false;
        }

        m_inputManager = std::make_unique<InputManager>();

        m_isRunning = true;
        return true;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Initialization error: " << e.what() << "\n";
        return false;
    }
}

void Engine::Run(){
    while(m_isRunning) {
        m_isRunning = HandleMessages();

        m_inputManager->Update();

        m_renderer->BeginFrame();
        m_renderer->Render();
        m_renderer->EndFrame();
    }
}

bool Engine::HandleMessages() {
    MSG msg = {};
    while (PeekMessageW(&msg, nullptr, 0, 0, PM_REMOVE)) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);

        if(msg.message == WM_QUIT) {
            return false;
        }
    }
    return true;
}

void Engine::Shutdown() {
    m_renderer.reset();
    m_inputManager.reset();
    m_window.reset();
}