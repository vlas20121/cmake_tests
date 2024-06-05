#https://github.com/arsenm/sanitizers-cmake
cmake_minimum_required(VERSION 3.6)
project(asan_test)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/externals/sanitizers-cmake/cmake" ${CMAKE_MODULE_PATH})
find_package(Sanitizers)
sanitizer_add_blacklist_file("blacklist.txt")
add_executable(${PROJECT_NAME} asan_test.cpp)
add_sanitizers(${PROJECT_NAME})