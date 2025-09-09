cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_COMPILER g++)

project(MyCppProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) 

add_executable(my_app main.cpp)