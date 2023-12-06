mkdir build
cd build
del /s CMakeCache.txt
cmake .. > cmake.log 2>&1
cmake --build . > build.log 2>&1
Debug\FutureTest.exe
