rem https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/installer/mingw-w64-install.exe/download
set toolset=G:\PF\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\
set cmake=G:\PF\CMake\bin
set CC=%toolset%gcc.exe
set CXX=%toolset%g++.exe
set path=%toolset%;%cmake%
