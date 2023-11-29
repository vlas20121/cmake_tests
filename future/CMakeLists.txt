#https://stackoverflow.com/questions/65860094/how-to-add-eigen-library-to-a-cmake-c-project-via-fetchcontent
cmake_minimum_required (VERSION 3.16)
project (FutureTest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

add_executable (FutureTest main.cpp)
