#https://habr.com/ru/post/581228/
cmake_minimum_required(VERSION 3.18)
project (conan_test)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Подключаем менеджер зависимостей Conan
list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})
if (NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.16.1/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake"
            EXPECTED_HASH SHA256=396e16d0f5eabdc6a14afddbcfff62a54a7ee75c6da23f32f7a31bc85db23484
            TLS_VERIFY ON)
endif ()
include(${CMAKE_BINARY_DIR}/conan.cmake)

# Подключаем репозиторий зависимостей https://conan.io
conan_add_remote(NAME conan-center INDEX 1 URL https://center.conan.io VERIFY_SSL True)

# Скачиваем нужные нам зависимости, например:
conan_cmake_configure(REQUIRES catch2/2.13.6 spdlog/1.8.5 threadpool/20140926 simdjson/0.9.6 icu/69.1 GENERATORS cmake_find_package)
conan_cmake_autodetect(settings)
conan_cmake_install(PATH_OR_REFERENCE . BUILD missing REMOTE conan-center SETTINGS ${settings})

# Делаем зависимости видимыми для CMake
find_package(Catch2) # фреймворк тестирования
find_package(ICU) # работа с юникодом
find_package(spdlog) # логирование
find_package(simdjson) # парсинг json с помощью simd
find_package(ThreadPool) # ThreadPoolExecutor

# Подключаем файлы с основным кодом
file(GLOB proj_sources src/*.cpp)
add_executable(app ${proj_sources})
# Линкуем зависимости для основного кода (имена для линковки можно вытащить из описания зависимостей)
target_link_libraries(app PRIVATE ThreadPool::ThreadPool spdlog::spdlog simdjson::simdjson ICU::io ICU::i18n ICU::uc ICU::data)

# Подключаем файлы с кодом тестов
list(FILTER proj_sources EXCLUDE REGEX ".*/Main.cpp$")
file(GLOB test_sources test/*.cpp)
add_executable(test ${proj_sources} ${test_sources})
# Линкуем зависимости для тестов
target_link_libraries(test PRIVATE Catch2::Catch2 ThreadPool::ThreadPool spdlog::spdlog simdjson::simdjson ICU::io ICU::i18n ICU::uc ICU::data)
