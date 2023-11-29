Как CMake'у указать путь для собранных .exe и .dll?

1 Я не нашел способа указать это прямо в параметрах CMake:

2 Но можно указать install путь в CMakeLists.txt:
https://stackoverflow.com/questions/543203/cmake-runtime-output-directory-on-windows
SET( CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${OUTPUT_DIRECTORY}")
SET( CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${OUTPUT_DIRECTORY}")
SET( CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${OUTPUT_DIRECTORY}")
SET( CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE "${OUTPUT_DIRECTORY}")
3 пример CMakeLists.txt
[
cmake_minimum_required(VERSION 3.6)
project(tmpnam)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ../rel)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG  ../deb)
add_executable(${PROJECT_NAME} main.cpp)
]

4 заместо "../rel" в "CMakeLists.txt" несложно поставить параметр:
if(DEFINED InstallDir)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${InstallDir})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG  ${InstallDir})
endif()
cmake -DCMAKE_BUILD_TYPE=Release -B Release_build -DInstallDir="../rel"

здесь "if(DEFINED InstallDir)" обеспечивает обратную совместимость:
 если InstallDir не задан, то ничего не изменится

