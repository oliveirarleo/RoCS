cmake_minimum_required(VERSION 3.9)
project(RoCS)

INCLUDE(FindPkgConfig)

#include_directories ("src/Kaiju")
#include_directories ("src/Pioneer_p3dx")
include_directories("src/lib/include")
include_directories("src/lib/include/stack")
include_directories("src/lib/remoteAPI")
include_directories("src/Kaiju")


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -DBUILD_SHARED_LIBS=OFF")

# definicoes da remoteAPI para CPP
add_definitions(-DNON_MATLAB_PARSING)
add_definitions(-DMAX_EXT_API_CONNECTIONS=255)
#add_definitions(-DO_NOT_USE_SHARED_MEMORY)

file(GLOB SOURCES "src/Pioneer_p3dx/*.cpp" "src/Pioneer_p3dx/*/*.cpp" "src/lib/*/*.cpp" "src/lib/*/*/*.cpp" "src/lib/*/*.c")
file(GLOB HEADERS "src/Pioneer_p3dx/*.h" "src/Pioneer_p3dx/*/*.h" "src/lib/*/*.h" "src/lib/*/*/*.h")

find_package(Threads)

add_executable(RoCS ${SOURCES} ${HEADERS})

target_link_libraries(RoCS ${CMAKE_THREAD_LIBS_INIT})

install(TARGETS RoCS RUNTIME DESTINATION bin)
