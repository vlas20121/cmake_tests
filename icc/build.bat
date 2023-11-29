call setup_toolset.bat
cmake  -G %CMAKE_GENERATOR_NAME% -T %CMAKE_TOOLSET_NAME%  -B bin > cmake.log 2>&1
cmake --build bin > build.log 2>&1
bin\Main.exe

rem cmake -DICC=ON -G %CMAKE_GENERATOR_NAME% -T %CMAKE_TOOLSET_NAME% > log.cmake.txt 2>&1
