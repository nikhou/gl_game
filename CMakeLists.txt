cmake_minimum_required(VERSION 3.26)
project(gl_game)

find_package(OpenGL)
find_package(glfw3 REQUIRED)

add_executable(gl_game src/main.c)
target_link_libraries(gl_game OpenGL::GL glfw)
