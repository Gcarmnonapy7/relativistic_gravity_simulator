cmake_minimum_required(VERSION 3.10)

project(RelativisticGravitySimulation)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find OpenMP
find_package(OpenMP REQUIRED)

# Find OpenGL and GLFW
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

# Add source files

# GLAD - we will include the GLAD source directly
add_library(glad src/glad.c)
target_include_directories(glad PUBLIC third_party/glad/include)

# Main executable
add_executable(${PROJECT_NAME} src/main.cpp
    src/physics.cpp
    src/renderer.cpp)

# Link libraries

target_link_libraries(gravity_sim
    OpenMP::OpenMP_CXX
    OpenGL::GL
    glfw
    glad
    pthread
    m
)

target_include_directories(gravity_sim PRIVATE src)
