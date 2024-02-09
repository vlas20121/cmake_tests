#https://stackoverflow.com/questions/9881288/compiling-a-boost-test-with-cmake
#https://cmake.org/cmake/help/latest/module/FindBoost.html
cmake_minimum_required(VERSION 3.0)
find_package(Boost CONFIG COMPONENTS system filesystem unit_test_framework REQUIRED)
add_excecutable(testTheTester boostTester.cpp)
target_link_libraries(testTheTester
  PRIVATE
  Boost::filesystem
  Boost::system
  Boost::unit_test_framework
)
add_test(testTheTester testTheTester)
