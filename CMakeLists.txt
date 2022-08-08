cmake_minimum_required(VERSION 3.14)
project(simple-chess-client VERSION 0.0.1 DESCRIPTION "Command line client to play chess")
set (srcfiles
	src/main.cpp)

set(CMAKE_CXX_STANDARD 17)
set(COMMON_FLAGS -Wall -Wextra -Wpedantic -Werror)

# Enable debug
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(chess-client
	${srcfiles})
target_link_libraries(chess-client ${CMAKE_SOURCE_DIR}/libs/simple-chess-games/bin/libsimple-chess-games.a)

include_directories(libs/simple-chess-games/include)
include_directories(src)
