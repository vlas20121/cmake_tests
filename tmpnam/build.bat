mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release .. > cmake.log 2>&1
cmake --build . --config Release > build.log 2>&1
..\rel\tmpnam.exe
