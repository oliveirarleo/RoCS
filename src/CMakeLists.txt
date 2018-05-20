cmake_minimum_required(VERSION 3.9)
project(Pioneer)

INCLUDE(FindPkgConfig)

#include_directories ("src/Kaiju")
#include_directories ("src/Pioneer_p3dx")
add_subdirectory(lib)

include_directories(lib/include/stack lib/remoteApi lib/include Kaiju)


set(CMAKE_CXX_STANDARD 17)
IF (CMAKE_COMPILER_IS_GNUCC)
    SET(CMAKE_CXX_FLAGS
            "${CMAKE_CXX_FLAGS} -Wall -DBUILD_SHARED_LIBS=OFF ")
ENDIF (CMAKE_COMPILER_IS_GNUCC)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -DBUILD_SHARED_LIBS=OFF")
# set(CMAKE_VERBOSE_MAKEFILE ON)

set(ARCH_SOURCES
        )

set(SOURCES
        ${ARCH_SOURCES}
        Pioneer_p3dx/main.cpp
        Pioneer_p3dx/Robot/pioneer_p3dx.cpp
        Pioneer_p3dx/Connection/connection.cpp
        Pioneer_p3dx/Sensors/sonar_vrep.cpp
        Pioneer_p3dx/Monitor/monitor_sonar_vrep.cpp
        Pioneer_p3dx/Plan/planner_pioneer_p3dx.cpp
        Pioneer_p3dx/Analyze/analyze_pioneer_p_3_dx.cpp
        Pioneer_p3dx/Knowledge/pioneer_p3dx_model.cpp
        Pioneer_p3dx/Actuators/wheel_vrep.cpp)

find_package(Threads)

add_executable(Pioneer ${SOURCES})

target_link_libraries(Pioneer ${CMAKE_THREAD_LIBS_INIT} remote_api pthread)

install(TARGETS Pioneer RUNTIME DESTINATION bin)
