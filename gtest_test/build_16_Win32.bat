mkdir build
cd build
cmake -G "Visual Studio 16 2019" -A Win32 .. > cmake.log 2>&1
cmake --build . > build.log 2>&1
tests\Debug\multiply_gtests.exe
