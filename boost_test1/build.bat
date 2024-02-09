:: Assuming you're executing these commands
:: from the root directory!
set BOOST_ROOT=D:\svn\external\boost\v_1.61.0\

mkdir build
cd build
cmake .. > 1.log
cmake --build . > 2.log
"./tests/Debug/string_utils_test.exe"