cmake_minimum_required(VERSION 3.27)
project(neomatrix)

set(CMAKE_CXX_STANDARD 20)

add_executable(neomatrix main.cpp
        MatrixCharacter.h
        MatrixCharacter.cpp)
