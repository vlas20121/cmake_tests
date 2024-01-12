#https://stackoverflow.com/questions/10472393/opencv-wont-compile-due-to-unresolved-externals-lnk2019
#https://stackoverflow.com/questions/77000339/error-c1189-when-compiling-opencv-for-arm64-at-amd64
#https://stackoverflow.com/questions/64156798/including-opencv-with-fetchcontent-does-not-work
cmake_minimum_required(VERSION 3.23)
project(my_project)
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        opencv
        GIT_REPOSITORY https://github.com/opencv/opencv.git
        GIT_TAG 4.6.0
        GIT_SHALLOW TRUE
        GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(opencv)

add_executable(my_target main.cpp)
target_include_directories(my_target PRIVATE
        ${OPENCV_CONFIG_FILE_INCLUDE_DIR}
        ${OPENCV_MODULE_opencv_core_LOCATION}/include
        ${OPENCV_MODULE_opencv_imgcodecs_LOCATION}/include
        )
target_link_libraries(my_target opencv_core opencv_imgcodecs)
