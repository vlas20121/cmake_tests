cmake_minimum_required(VERSION 3.1)
project(mytest Fortran)
#https://gist.github.com/scivision/bddf416190320e844bd6b5f9846b1396

# NOTE: -fdefault-integer-8 -m64  are crucial for MKL to avoid SIGSEGV at runtime!
add_compile_options(-fdefault-integer-8 -m64)

add_executable(inteld gesvd.f90)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
# https://software.intel.com/en-us/articles/intel-mkl-link-line-advisor 
find_package(MKL)
if(MKL_FOUND)
    include_directories(${MKL_INCLUDE_DIRS})
    target_link_libraries(inteld ${MKL_LIBRARIES} pthread dl)
else()
    find_package(BLAS REQUIRED)
    target_link_libraries(inteld blas)
endif()

