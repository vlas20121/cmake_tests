mkdir build
cd build
:: -DCMAKE_BUILD_TYPE=Release
cmake -G "Visual Studio 17 2022" -A ARM64EC .. > cmake.log 2>&1
cmake --build . > build.log 2>&1
Debug\simplest.exe
