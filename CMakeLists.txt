cmake_minimum_required(VERSION 3.0)

project(Playground)

set(SOURCE  src/core.cpp 
            src/math.hpp
            src/renderable.hpp
            src/renderable.cpp)

add_subdirectory(submodules/glfw)
add_subdirectory(submodules/glad)

include_directories(
    submodules/glfw/include
    submodules/glad/include)

link_libraries(glad glfw)

add_executable(${PROJECT_NAME} ${SOURCE})

target_precompile_headers(${PROJECT_NAME}
    PRIVATE
    <vector>
    )