cmake_minimum_required(VERSION 4.0.2)
project(GameEngine VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
configure_file(GameEngineConfig.h.in GameEngineConfig.h)

set(GLFW_PATH "${CMAKE_CURRENT_SOURCE_DIR}/dependency/glfw")
set(GLAD_INCLUDE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/dependency")

add_executable(
        GameEngine
        src/main.cpp
        src/graphics/Window.cpp
        ${GLAD_INCLUDE_PATH}/glad/gl.c)

add_subdirectory(${GLFW_PATH})

find_package(OpenGL REQUIRED)

target_include_directories( GameEngine
        PUBLIC
        ${PROJECT_BINARY_DIR}
        ${GLAD_INCLUDE_PATH} # GLAD headers
        ${GLFW_PATH}/include )

target_link_libraries(
        GameEngine
        glfw
        OpenGL::GL
        ${CMAKE_DL_LIBS}) # needed for dynamic loading on Linux