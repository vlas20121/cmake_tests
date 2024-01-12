mkdir build_17_v143_x64
cd build_17_v143_x64
cmake -G "Visual Studio 17 2022" -T v143 -A X64 -DCMAKE_BUILD_TYPE=Release .. > cmake.log 2>&1
cmake --build . > build.log 2>&1
bin\Debug\my_target.exe