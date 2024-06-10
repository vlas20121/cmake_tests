mkdir %BUILD_DIR%
cd %BUILD_DIR%

:: -G "Visual Studio 16 2019" -A x64
:: -G "Visual Studio 17 2022" -T="ClangCL" -A x64
:: -G "Visual Studio 17 2022" -A x64

cmake .. ^
 -DCMAKE_VERBOSE_MAKEFILE:BOOL=ON ^
 -G "Visual Studio 17 2022" -T="v143" -A x64 ^
 -DBUILD_TYPE=%BUILD_TYPE% .. > 1.log 2>&1
cmake --build . --config %BUILD_TYPE% > 2.log 2>&1

call ../../../vc_toolsets.bat

set PATH=%vc22_v143%;%PATH%

tests\%BUILD_TYPE%\asan_test_cpp.exe > asan_test_cpp.%BUILD_TYPE%.log 2>&1
tests\%BUILD_TYPE%\shortest_ext_test_cpp.exe > shortest_ext_test_cpp.%BUILD_TYPE%.log 2>&1