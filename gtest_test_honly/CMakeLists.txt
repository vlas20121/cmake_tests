cmake_minimum_required(VERSION 3.16)

project(GoogleTestExample LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# define output directories
#set(BINARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)


include_directories("${PROJECT_SOURCE_DIR}")
include_directories("gtest/include")

# add executable file
set(SRC_LIST Source.cpp)

# add library
add_executable(${PROJECT_NAME} ${SRC_LIST})

#set_target_properties( ${PROJECT_NAME} PROPERTIES
#  RUNTIME_OUTPUT_DIRECTORY_DEBUG "${BINARY_OUTPUT_DIRECTORY}"
#  RUNTIME_OUTPUT_DIRECTORY_RELEASE "${BINARY_OUTPUT_DIRECTORY}")
