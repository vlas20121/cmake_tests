#https://github.com/arsenm/sanitizers-cmake
cmake_minimum_required(VERSION 3.6)
project(flg)

include(CMakePrintHelpers)
include(CheckCXXCompilerFlag)

check_cxx_compiler_flag("/fsanitize=address" asan_ok)
cmake_print_variables(CMAKE_CXX_COMPILER_ID CMAKE_CXX_COMPILER asan_ok)