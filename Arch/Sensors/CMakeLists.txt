cmake_minimum_required(VERSION 3.9)
project(Sensors)

set(CMAKE_CXX_STANDARD 17)

add_executable(Sensors range.cpp sensor.cpp sonar.cpp)