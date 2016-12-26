cmake_minimum_required(VERSION 3.6)
project(GameOfLifeMode)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")



set(SOURCE_FILES main.cpp src/Mode.h src/Mode.cpp src/SimpleMode.cpp src/SimpleMode.h src/ModeConquest.cpp src/ModeConquest.h
        HashlifeGameOfLife/src/TreeNode.cpp HashlifeGameOfLife/src/TreeNode.h HashlifeGameOfLife/src/TreeUniverse.cpp
        HashlifeGameOfLife/src/TreeUniverse.h HashlifeGameOfLife/src/TreeHashMap.cpp HashlifeGameOfLife/src/TreeHashMap.h
        HashlifeGameOfLife/src/CanonicalTreeNode.cpp HashlifeGameOfLife/src/CanonicalTreeNode.h
        HashlifeGameOfLife/src/HashLifeTreeNode.cpp HashlifeGameOfLife/src/HashLifeTreeNode.h src/Zone.cpp src/Zone.h src/Point.cpp src/Point.h)
add_executable(GameOfLifeMode ${SOURCE_FILES})