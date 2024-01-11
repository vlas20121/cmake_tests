cmake_minimum_required (VERSION 3.16)
project(string_utils_test)

file(GLOB_RECURSE  CPP "../src/*_test.cpp")
file(GLOB_RECURSE  H "../src/*_test.h")

add_compile_definitions(TESTS)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(${PROJECT_NAME} ${CPP} ${H})

target_link_libraries(${PROJECT_NAME}
 PRIVATE
  GTest::GTest
  string_utils
)

add_test(run_test ${PROJECT_NAME})
