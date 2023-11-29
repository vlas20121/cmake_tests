rem cmake -DCMAKE_BUILD_TYPE=Release -G "Unix Makefiles" -B bin > cmake.log
cmake -G "Visual Studio 16 2019" -DCMAKE_BUILD_TYPE=Release -B bin > cmake.log 2>&1
cmake --build bin --config Release > build.log 2>&1
