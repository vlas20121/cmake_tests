��� CMake'� ������� ���� ��� ��������� .exe � .dll?

1 � �� ����� ������� ������� ��� ����� � ���������� CMake:

2 �� ����� ������� install ���� � CMakeLists.txt:
https://stackoverflow.com/questions/543203/cmake-runtime-output-directory-on-windows
SET( CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${OUTPUT_DIRECTORY}")
SET( CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${OUTPUT_DIRECTORY}")
SET( CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${OUTPUT_DIRECTORY}")
SET( CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE "${OUTPUT_DIRECTORY}")
3 ������ CMakeLists.txt
[
cmake_minimum_required(VERSION 3.6)
project(tmpnam)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ../rel)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG  ../deb)
add_executable(${PROJECT_NAME} main.cpp)
]

4 ������� "../rel" � "CMakeLists.txt" �������� ��������� ��������:
if(DEFINED InstallDir)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${InstallDir})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG  ${InstallDir})
endif()
cmake -DCMAKE_BUILD_TYPE=Release -B Release_build -DInstallDir="../rel"

����� "if(DEFINED InstallDir)" ������������ �������� �������������:
 ���� InstallDir �� �����, �� ������ �� ���������

