#https://stackoverflow.com/questions/65860094/how-to-add-eigen-library-to-a-cmake-c-project-via-fetchcontent
cmake_minimum_required(VERSION 3.15)
project(EigenTest)

include(FetchContent)
FetchContent_Declare(Eigen3 GIT_REPOSITORY "https://gitlab.com/libeigen/eigen.git" GIT_TAG "3.4.0") 
FetchContent_MakeAvailable(Eigen3)

add_executable(EigenTest main.cpp)
target_link_libraries(EigenTest Eigen3::Eigen)
