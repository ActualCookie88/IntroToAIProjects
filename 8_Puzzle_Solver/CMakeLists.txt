cmake_minimum_required(VERSION 3.16)
project(EightPuzzleSolver)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

# Include headers
include_directories(header)

# Add executable and source files
add_executable(puzzle
    main.cpp
    src/globals.cpp
    src/Heuristics.cpp
    src/Puzzle.cpp
    src/Search.cpp
)