cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Release)

project(ctest)

add_subdirectory(src)
enable_testing()
add_subdirectory(tests)