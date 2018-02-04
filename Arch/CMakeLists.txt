cmake_minimum_required(VERSION 3.9)
project(Arch)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES "*.cpp" "*/*.cpp" "*/*/*.cpp")

add_executable(Arch ${SOURCES})