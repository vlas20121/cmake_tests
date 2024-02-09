:: Assuming you're executing these commands
:: from the root directory!
mkdir build
cd build
set CMAKE_PREFIX_PATH=D:\svn\external\GoogleTest\1.14.0\build\googletest\generated\
#cmake .. --trace-expand > 1.log 2>&1
cmake .. > 1.log 2>&1
cmake --build . > 2.log 2>&1
"./tests/Debug/multiply_gtests.exe"