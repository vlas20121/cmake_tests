cmake_minimum_required(VERSION 3.16)
project(testTheTester LANGUAGES CXX)
#https://stackoverflow.com/questions/9881288/compiling-a-boost-test-with-cmake
#https://cmake.org/cmake/help/latest/module/FindBoost.html
find_package(Boost CONFIG COMPONENTS system filesystem unit_test_framework REQUIRED)
add_executable(testTheTester boostTester.cpp)
target_link_libraries(testTheTester
	${Boost_LIBRARIES}
	${Boost_FILESYSTEM_LIBRARY}
	${Boost_SYSTEM_LIBRARY}
	${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)
add_test(testTheTester testTheTester)
