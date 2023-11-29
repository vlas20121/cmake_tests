cmake_minimum_required(VERSION 3.6)

project(HelloWorld)

file(
    WRITE main.cpp 
        "#include <iostream>\n"
        "int main() { std::cout << \"Hello World!\" << std::endl; return 0; }"
)
add_executable(${PROJECT_NAME} main.cpp)
