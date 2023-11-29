cmake_minimum_required(VERSION 3.9)
project(openmp_test LANGUAGES CXX)

find_package(OpenMP REQUIRED)
add_executable(openmp_test main.cpp)
target_link_libraries(openmp_test PRIVATE OpenMP::OpenMP_CXX)
