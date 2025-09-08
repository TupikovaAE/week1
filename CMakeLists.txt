cmake_minimum_required(VERSION 3.10)
project(ASCII-Tetris C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

if(WIN32)
    add_definitions(-D_WIN32)
endif()

add_executable(tetris main.c tetris.c)

target_include_directories(tetris PRIVATE .)