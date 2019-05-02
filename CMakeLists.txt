cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(learning_c VERSION 0.1 LANGUAGES CXX C)

# Required for ycm (YouCompleteMe vim plugin) support
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(ext/googletest)

add_executable(learning_c learning_c.cpp)

target_link_libraries(learning_c
	gtest_main
    gmock
)


add_executable(main main.c)
