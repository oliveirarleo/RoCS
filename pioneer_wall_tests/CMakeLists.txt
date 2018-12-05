cmake_minimum_required(VERSION 3.9)
project(Pioneer)

INCLUDE(FindPkgConfig)

add_subdirectory(remote_api_vrep)

include_directories(remote_api_vrep Kaiju)


set(CMAKE_CXX_STANDARD 17)
IF (CMAKE_COMPILER_IS_GNUCC)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -DBUILD_SHARED_LIBS=OFF -lpthread")
ENDIF (CMAKE_COMPILER_IS_GNUCC)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -DBUILD_SHARED_LIBS=OFF")
# set(CMAKE_VERBOSE_MAKEFILE ON)



set(SOURCES
        pioneer_p3dx_avoid_wall/Actuators/wheel_vrep.cpp

        pioneer_p3dx_avoid_wall/Sensors/orientation_vrep_sensor.cpp
        pioneer_p3dx_avoid_wall/Sensors/range_vrep_sensor.cpp
        pioneer_p3dx_avoid_wall/Sensors/position_vrep_sensor.cpp

        pioneer_p3dx_avoid_wall/Connection/connection.cpp


        pioneer_p3dx_avoid_wall/Knowledge/pioneer_p3dx_model.cpp
        pioneer_p3dx_avoid_wall/Knowledge/avoid_wall_model.cpp
        pioneer_p3dx_avoid_wall/Knowledge/p3dx_knowledge.cpp

        pioneer_p3dx_avoid_wall/Robot/pioneer_p3dx.cpp

        main.cpp

        pioneer_p3dx_avoid_wall/Monitor/orientation_vrep_monitor.cpp pioneer_p3dx_avoid_wall/Monitor/orientation_vrep_monitor.h pioneer_p3dx_avoid_wall/Monitor/position_vrep_monitor.cpp pioneer_p3dx_avoid_wall/Monitor/position_vrep_monitor.h pioneer_p3dx_avoid_wall/Monitor/range_vrep_monitor.cpp pioneer_p3dx_avoid_wall/Monitor/range_vrep_monitor.h pioneer_p3dx_avoid_wall/Analyze/pass_vrep_orientation.cpp pioneer_p3dx_avoid_wall/Analyze/pass_vrep_orientation.h pioneer_p3dx_avoid_wall/Analyze/pass_vrep_position.cpp pioneer_p3dx_avoid_wall/Analyze/pass_vrep_position.h pioneer_p3dx_avoid_wall/Analyze/pass_vrep_range.cpp pioneer_p3dx_avoid_wall/Analyze/pass_vrep_range.h)

find_package(Threads)

add_executable(Pioneer ${SOURCES})

target_link_libraries(Pioneer ${CMAKE_THREAD_LIBS_INIT} remote_api pthread)

install(TARGETS Pioneer RUNTIME DESTINATION bin)
