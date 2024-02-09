::set BOOST_ROOT=D:\svn\external\boost\v_1.74.0\
set Boost_DIR=D:\svn\external\boost\v_1.74.0\lib\cmake\Boost-1.74.0\
::set Boost_INCLUDE_DIR=D:\svn\external\boost\v_1.74.0\

mkdir build
cd build
cmake .. > 1.log
cmake --build . > 2.log
"./Debug/boost_test.exe"