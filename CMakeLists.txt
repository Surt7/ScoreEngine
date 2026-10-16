cmake_minimum_required(VERSION 4.2)
project(ScoreEngine)

set(CMAKE_CXX_STANDARD 20)

add_executable(ScoreEngine main.cpp
        include/Event.h
        include/ScoreEngine.h
        src/ScoreEngine.cpp
        include/IRule.h)

target_compile_options(ScoreEngine PRIVATE -Wall -Wextra -Wpedantic)


target_include_directories(ScoreEngine PRIVATE include)