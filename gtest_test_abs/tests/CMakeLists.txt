cmake_minimum_required (VERSION 3.16)
project(multiply_gtests)

file(GLOB_RECURSE  CPP "*.cpp")
file(GLOB_RECURSE  H "*.h")

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

enable_testing()
find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME} ${CPP} ${H})
target_link_libraries(${PROJECT_NAME} GTest::gtest GTest::gtest_main multiply)

add_test(run_test ${PROJECT_NAME})
