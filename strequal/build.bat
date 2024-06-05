:: Assuming you're executing these commands
:: from the root directory!
mkdir build
cd build
::set extroot=E:\svn\external\

set confParam="Debug"
cmake ..

set confParam="Release"
cmake ..

set confParam=
cmake ..
