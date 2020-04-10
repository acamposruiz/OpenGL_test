cmake_minimum_required(VERSION 3.13)
project(minesweeper-app)

add_executable(minesweeper "")

find_package(GLFW3 REQUIRED)

target_sources(minesweeper PUBLIC main.cpp glad.c)
target_link_libraries(minesweeper PUBLIC mingw32 glfw3)
target_include_directories(minesweeper PRIVATE
        include
        external/alib-util
        external/alib-math
        external/stb)
