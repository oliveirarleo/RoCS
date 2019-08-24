cmake_minimum_required(VERSION 3.1)

project(robotnik_follow)

INCLUDE(FindPkgConfig)

include_directories(../remote_api_vrep ../FRoCS)

add_subdirectory(../remote_api_vrep build)

set(CMAKE_CXX_STANDARD 17)
IF (CMAKE_COMPILER_IS_GNUCC)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -DBUILD_SHARED_LIBS=OFF -lpthread")
ENDIF (CMAKE_COMPILER_IS_GNUCC)


file(GLOB SOURCES "./*/*.cpp"  "./*/*/*.cpp" main.cpp)

file(GLOB HEADERS "./*/*/*.h" "./*/*.h")

find_package(Threads)

add_executable(robotnik_follow ${SOURCES} ${HEADERS})

target_link_libraries(robotnik_follow ${CMAKE_THREAD_LIBS_INIT} remote_api pthread)

install(TARGETS robotnik_follow RUNTIME DESTINATION bin)
