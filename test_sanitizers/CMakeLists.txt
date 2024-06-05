#https://github.com/arsenm/sanitizers-cmake
cmake_minimum_required(VERSION 2.8.12)
project("test-sanitizers")

#set(SANITIZE_ADDRESS TRUE)
set(SANITIZE_MEMORY TRUE)
#set(SANITIZE_THREAD TRUE)
#set(SANITIZE_UNDEFINED TRUE)

#
# search for sanitizers
#
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
find_package(Sanitizers)

# Function to add testcases.
function(add_testcase TESTNAME SOURCEFILES)
	# remove ${TESTNAME} from ${ARGV} to use ${ARGV} as ${SOURCEFILES}
	list(REMOVE_AT ARGV 0)

	# add a new executable
	add_executable(${TESTNAME} ${ARGV})

	# add a testcase for executable
	add_test(${TESTNAME} ${TESTNAME})
endfunction(add_testcase)

# Function to add testcases with asan enabled.
function(add_sanitized_testcase TESTNAME SOURCEFILES)
	add_testcase(${TESTNAME} ${SOURCEFILES})
	add_sanitizers(${TESTNAME})
endfunction(add_sanitized_testcase)

#
# add testcases
#
add_sanitized_testcase("asan_test_cpp" asan_test.cpp)
add_sanitized_testcase("shortest_ext_test_cpp" shortest.ext.test.cpp)

set_tests_properties(
	"asan_test_cpp"
	"shortest_ext_test_cpp"
PROPERTIES
	WILL_FAIL TRUE
)
