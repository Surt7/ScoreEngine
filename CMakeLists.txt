cmake_minimum_required(VERSION 4.2)
project(ScoreEngine)
find_package(nlohmann_json REQUIRED)


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
        src/core/GameSession.cpp
        include/core/Score.h
)

target_compile_options(ScoreEngine PRIVATE -Wall -Wextra -Wpedantic)


target_include_directories(ScoreEngine PRIVATE include)

target_link_libraries(ScoreEngine PRIVATE
        nlohmann_json::nlohmann_json
        ws2_32
)