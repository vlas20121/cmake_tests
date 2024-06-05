cmake_minimum_required(VERSION 3.6)
set(CMAKE_CXX_STANDARD 98)
project(simplest)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /fsanitize=address")
#target_compile_options(${PROJECT_NAME} PRIVATE -fsanitize=address)
#target_link_options(${PROJECT_NAME} PRIVATE -fsanitize=address)

add_executable(${PROJECT_NAME} main.cpp)
