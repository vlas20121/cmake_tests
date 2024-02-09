:: Assuming you're executing these commands
:: from the root directory!
mkdir build
cd build
cmake .. > 1.log
cmake --build . > 2.log
"./Debug/GoogleTestExample.exe"