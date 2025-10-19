#pragma once
#include <Windows.h>

class InputManager {
public:
    InputManager();
    ~InputManager();

    void Update();

    bool IsKeyPressed(int key) const;
    bool IsKeyDown(int key) const;
    bool IsKeyReleased(int key) const;

private:
    bool m_keyStates[256];
    bool m_prevKeyStates[256];
};