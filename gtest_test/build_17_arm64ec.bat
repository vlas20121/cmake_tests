mkdir build
cd build
cmake -G "Visual Studio 17 2022" -A ARM64EC .. > cmake.log 2>&1
cmake --build . > build.log 2>&1
tests\Debug\multiply_gtests.exe
