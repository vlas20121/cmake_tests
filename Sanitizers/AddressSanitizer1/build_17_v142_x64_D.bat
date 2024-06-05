mkdir build
cd build
cmake -G "Visual Studio 17 2022" -T v142 -A X64 -DCMAKE_BUILD_TYPE=Debug .. > cmake.log 2>&1
cmake --build . > build.log 2>&1

set vc=C:\Program Files\Microsoft Visual Studio\2022\Community\
set asan=C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.29.30133\bin\HostX64\x64\
set PATH=%PATH%;%asan%
Debug\asan-demo.exe
