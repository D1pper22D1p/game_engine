#include "Engine.h"
#include <iostream>

int main(){
    try
    {
        Engine engine;

        if (!engine.Initialize(1280, 720, "DirectX Game Engine")) {
            std::cerr <<"Failed to initialized engine\n";
            return -1;
        }

        engine.Run();
        engine.Shutdown();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Fatal error: " << e.what() << "\n";
        return -1;
    }

    return 0;
}