cmake_minimum_required(VERSION 4.2)
project(ScoreEngine)

set(CMAKE_CXX_STANDARD 20)

add_executable(ScoreEngine main.cpp
        include/core/Event.h
        include/core/ScoreEngine.h
        src/core/ScoreEngine.cpp
        include/rules/IRule.h
        include/rules/Rules.h
        include/parser/EventParser.h
        src/parse/EventParser.cpp
        include/display/ConsoleDisplay.h
        src/display/ConsoleDisplay.cpp
        include/core/GameSession.h
        src/core/GameSession.cpp)

target_compile_options(ScoreEngine PRIVATE -Wall -Wextra -Wpedantic)


target_include_directories(ScoreEngine PRIVATE include)