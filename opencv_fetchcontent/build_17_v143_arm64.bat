mkdir build_17_v143_arm64_std17_F
cd build_17_v143_arm64_std17_F
cmake -DCV_ENABLE_INTRINSICS=OFF ^
-DENABLE_SSE=OFF ^
-DENABLE_SSE2=OFF ^
-DENABLE_SSE3=OFF ^
-DENABLE_SSE41=OFF ^
-DENABLE_SSE42=OFF ^
-DENABLE_SSSE3=OFF ^
-G "Visual Studio 17 2022" -T v143 -A arm64 -DCMAKE_BUILD_TYPE=Release .. > cmake.log 2>&1
cmake --build . > build.log 2>&1
bin\Debug\my_target.exe
