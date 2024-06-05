mkdir %BUILD_DIR%
cd %BUILD_DIR%

:: -G "Visual Studio 17 2022" -T="ClangCL" -A x64
:: -G "Visual Studio 17 2022" -A x64

cmake .. ^
 -G "Visual Studio 17 2022" -A x64 ^
 -DBUILD_TYPE=%BUILD_TYPE%^
 -DSANITIZE_ADDRESS=On^
 -DSANITIZE_MEMORY=Off^
 -DSANITIZE_THREAD=Off^
 -DSANITIZE_UNDEFINED=On^
.. > 1.log 2>&1
cmake --build . --config %BUILD_TYPE% > 2.log 2>&1

set asan=C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.40.33807\bin\HostX64\x64\
set PATH=%PATH%;%asan%
%BUILD_TYPE%\asan_test.exe > ../log%BUILD_TYPE% 2>&1