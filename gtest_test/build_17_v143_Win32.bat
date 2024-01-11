mkdir build
cd build
cmake -G "Visual Studio 17 2022" -T v143 -A Win32 -DCMAKE_BUILD_TYPE=Release .. > cmake.log 2>&1
cmake --build . > build.log 2>&1
tests\Debug\multiply_gtests.exe
