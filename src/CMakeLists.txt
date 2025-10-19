find_package(directx-headers CONFIG REQUIRED)
find_package(directxmath CONFIG REQUIRED)

add_executable(GameEngine
    main.cpp
    Engine.cpp
    Engine.h
    Renderer.cpp
    Renderer.h
    Window.cpp
    Window.h
    InputManager.cpp
    InputManager.h
    Mesh.h
)

# Link only system libraries that have actual .lib files
target_link_libraries(GameEngine
    PRIVATE
    d3d12.lib
    dxgi.lib
    d3dcompiler.lib
    kernel32.lib
    user32.lib
    gdi32.lib
    winspool.lib
    comdlg32.lib
    advapi32.lib
    shell32.lib
    ole32.lib
    oleaut32.lib
    uuid.lib
    odbc32.lib
    odbccp32.lib
)

# Include header-only libraries
target_include_directories(GameEngine
    PRIVATE
    ${directx-headers_INCLUDE_DIRS}
    ${directxmath_INCLUDE_DIRS}
)

set_target_properties(GameEngine PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)