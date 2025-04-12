cmake_minimum_required(VERSION 3.30)
project(repo_github)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(
        repo_github main.cpp
        include/memory.hpp
        src/memory.cpp

)
