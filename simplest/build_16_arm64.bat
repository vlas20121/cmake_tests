mkdir build
cd build
cmake -G "Visual Studio 16 2019" -A ARM64 -DCMAKE_BUILD_TYPE=Release .. > cmake.log 2>&1
cmake --build . > build.log 2>&1
Debug\simplest.exe
