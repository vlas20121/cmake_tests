mkdir build
cd build
#cmake -G "Visual Studio 17 2022" -T="ClangCL" -A X64 .. > cmake.log 2>&1
cmake -T="ClangCL" -A X64 .. > cmake.log 2>&1
cmake --build . > build.log 2>&1
Debug\simplest.exe
