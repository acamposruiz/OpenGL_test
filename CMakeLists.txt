cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(recipe-01 LANGUAGES CXX)

add_subdirectory(Dependecies/glfw)
include_directories(Dependecies/glfw/include)
include_directories(Dependecies/glfw/deps)

add_executable(Application src/Application.cpp)

target_link_libraries(Application glfw ${GLFW_LIBRARIES})