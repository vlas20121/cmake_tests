cmake_minimum_required(VERSION 3.16)
project(gtest_string LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package( Boost REQUIRED COMPONENTS program_options regex )
include_directories( ${Boost_INCLUDE_DIRS} )
add_executable( run main.cpp ) # Example application based on main.cpp

# Alternatively you could use ${Boost_LIBRARIES} here.
target_link_libraries( run ${Boost_PROGRAM_OPTIONS_LIBRARY} ${Boost_REGEX_LIBRARY} )
