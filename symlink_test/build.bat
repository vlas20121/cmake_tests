rem cmake -DCMAKE_BUILD_TYPE=Release -G "Unix Makefiles" -B bin > cmake.log
cmake -DCMAKE_BUILD_TYPE=Release -B bin > cmake.log 2>&1
cmake --build bin > build.log 2>&1
bin\Debug\symlink_test.exe
