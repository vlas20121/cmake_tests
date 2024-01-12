mkdir build
cd build
cmake --debug-trycompile .. > cmake.log 2>&1
cmake --build . > build.log 2>&1
bin\Debug\my_target.exe
