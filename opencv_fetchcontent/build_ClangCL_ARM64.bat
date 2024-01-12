mkdir build_ClangCL_ARM64_std17
cd build_ClangCL_ARM64_std17
cmake -G "Visual Studio 17 2022" -T="ClangCL" -A ARM64 .. > cmake.log 2>&1
cmake --build . > build.log 2>&1
bin\Debug\my_target.exe
