cmake_minimum_required(VERSION 3.6)

project(simplest)

file(
    WRITE main.cpp 
        "#include <iostream>\n"
        "int main() { std::cout << \"Hello World!\" << std::endl; return 0; }"
)
message('MSCVersionShortMajor=' VC${MSCVersionShortMajor})
add_executable(${PROJECT_NAME} main.cpp)
