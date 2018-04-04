cmake_minimum_required(VERSION 3.9)
project(RoCS)

#add_subdirectory (src/Arch)
#add_subdirectory (src/Implementation)
#
set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ")


file(GLOB SOURCES "src/Implementation/*.cpp" "src/Implementation/*/*.cpp" )

add_executable(cmpl ${SOURCES})