cmake_minimum_required(VERSION 3.2)

project(tetris)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -pedantic -pipe")

set(TETRIS_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
set(TETRIS_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/src/include)

file(GLOB TETRIS_SOURCE_FILES "${TETRIS_SOURCE_DIR}/*.c")

include_directories(${TETRIS_INCLUDE_PATH})
add_executable(tetris ${TETRIS_SOURCE_FILES})