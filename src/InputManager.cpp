#include "InputManager.h"
#include <cstring>

InputManager::InputManager() {
    std::memset(m_keyStates, 0, sizeof(m_keyStates));
    std::memset(m_prevKeyStates, 0, sizeof(m_prevKeyStates));
}

InputManager::~InputManager() {}

void InputManager::Update() {
    std::memcpy(m_prevKeyStates, m_keyStates, sizeof(m_keyStates));
    
    for (int i = 0; i < 256; ++i) {
        m_keyStates[i] = (GetAsyncKeyState(i) & 0x8000) != 0;
    }
}

bool InputManager::IsKeyPressed(int key) const {
    return m_keyStates[key] && !m_prevKeyStates[key];
}

bool InputManager::IsKeyDown(int key) const {
    return m_keyStates[key];
}

bool InputManager::IsKeyReleased(int key) const {
    return !m_keyStates[key] && m_prevKeyStates[key];
}