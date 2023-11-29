rem cmake -DCMAKE_BUILD_TYPE=Release -G "Unix Makefiles" -B bin > cmake.log 2>&1
rem cmake -DCMAKE_BUILD_TYPE=Release -B bin > cmake.log 2>&1
rem cmake -T clangcl -DCMAKE_BUILD_TYPE=Release -B bin > cmake.log 2>&1
cmake -G "Visual Studio 16 2019" -T clangcl -DCMAKE_BUILD_TYPE=Release -B bin > cmake.log 2>&1
rem cmake -G "Visual Studio 16 2019" -DCMAKE_BUILD_TYPE=Release -B bin > cmake.log 2>&1

cmake --build bin > build.log 2>&1
bin\Debug\app.exe
bin\Debug\test.exe
