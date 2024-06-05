cmake_minimum_required(VERSION 3.1)
project(asan-demo C)

set(HEADERS
  "include/asan-demo.h"
)
set(SRC
  "src/asan-demo.c"
  "src/main.c"
)

add_executable(asan-demo ${SRC} ${HEADERS})
target_include_directories(asan-demo PUBLIC "include")

if(CMAKE_BUILD_TYPE MATCHES "Debug")
  set(
    CMAKE_C_FLAGS
    "${CMAKE_C_FLAGS} -fsanitize=undefined -fsanitize=address  /Zi"
    #"${CMAKE_C_FLAGS} -Werror -fsanitize=undefined -fsanitize=address"
  )
  target_link_options(asan-demo
    BEFORE PUBLIC -fsanitize=undefined PUBLIC -fsanitize=address
  )
endif()
