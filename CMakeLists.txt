cmake_minimum_required(VERSION 3.14)
project(GameEngine VERSION 1.0)

include(FetchContent)

FetchContent_Declare(
        glm
        GIT_REPOSITORY https://github.com/g-truc/glm.git
        GIT_TAG 1.0.1   # pick a version tag/commit
)
FetchContent_MakeAvailable(glm)
set(CMAKE_CXX_STANDARD 20)
configure_file(GameEngineConfig.h.in GameEngineConfig.h)

set(GLFW_PATH "${CMAKE_CURRENT_SOURCE_DIR}/dependency/glfw")
set(GLAD_INCLUDE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/dependency")

add_executable(
        GameEngine
               src/main.cpp
               src/gl.c
)

add_subdirectory(${GLFW_PATH})

target_include_directories(
            GameEngine
                PUBLIC
                    ${PROJECT_BINARY_DIR}
                    ${GLAD_INCLUDE_PATH} # GLAD headers
                    ${GLFW_PATH}/include
)

target_link_libraries(
        GameEngine
        glm::glm
        glfw
        ${CMAKE_DL_LIBS}   # needed for dynamic loading on Linux
)