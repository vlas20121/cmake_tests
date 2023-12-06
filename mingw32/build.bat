::call setup_toolset.bat
::make  -G "MinGW Makefiles" -B bin > cmake.log 2>&1
cmake  -B bin . > cmake.log 2>&1
cmake --build bin > build.log 2>&1
bin\Debug\Main.exe
