set BOOST_ROOT=C:\Users\andrey.vlasov\.conan2\p\boost0604266816385\p\

mkdir build
cd build
cmake .. > 1.log
cmake --build . > 2.log
"./Debug/boost_test.exe"