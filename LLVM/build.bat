call setup_toolset.bat
cmake  -G "MinGW Makefiles" -DCMAKE_CXX_COMPILER=%CXX% -B bin > cmake.log 2>&1
cmake --build bin > build.log 2>&1
bin\Main.exe
