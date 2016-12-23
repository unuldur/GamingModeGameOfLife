cmake_minimum_required(VERSION 3.6)
project(GameOfLifeMode)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(HashlifeGameOfLife)
set(SOURCE_FILES main.cpp src/Mode.h src/SimpleMode.cpp src/SimpleMode.h src/ModeConquest.cpp src/ModeConquest.h)
add_executable(GameOfLifeMode ${SOURCE_FILES})