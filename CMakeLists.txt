cmake_minimum_required(VERSION 3.0)

project(Playground)

if(WIN32)
    set(PLATFORM_HEADER <windows.h>)
endif()

set(SOURCE src/core.cpp)

add_subdirectory(submodules/glfw)
add_subdirectory(submodules/glad)

include_directories(
    submodules/glfw/include
    submodules/glad/include
    )

link_libraries(glad glfw)

add_executable(${PROJECT_NAME} ${SOURCE})