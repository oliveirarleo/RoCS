cmake_minimum_required(VERSION 3.9)
project(Arch)

set(CMAKE_CXX_STANDARD 17)

include_directories(ConcreteClasses)
include_directories(Util)
include_directories(Sensors)

file(GLOB SOURCES "*.cpp" "*/*.cpp" "*/*/*.cpp")

add_executable(Arch ${SOURCES})