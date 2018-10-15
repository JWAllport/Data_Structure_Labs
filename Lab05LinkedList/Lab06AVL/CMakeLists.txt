cmake_minimum_required(VERSION 3.8)
project(LAB6)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES AVLTree.cpp AVLTree.h commondict.txt Game.cpp Game.hpp LL.cpp LL.h mainWordHub.cpp NodeL.cpp NodeL.hpp NodeT.cpp NodeT.hpp scrabble.txt testdict.txt)
add_executable(LAB6 ${SOURCE_FILES})
