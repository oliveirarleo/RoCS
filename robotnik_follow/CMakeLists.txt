cmake_minimum_required(VERSION 3.13)
project(robotnik_follow)

INCLUDE(FindPkgConfig)


include_directories(../remote_api_vrep ../FRoCS)


set(CMAKE_CXX_STANDARD 17)
IF (CMAKE_COMPILER_IS_GNUCC)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -DBUILD_SHARED_LIBS=OFF -lpthread")
ENDIF (CMAKE_COMPILER_IS_GNUCC)



include_directories(Kaiju)
include_directories(Kaiju/Actuators)
include_directories(Kaiju/Analyze)
include_directories(Kaiju/Execute)
include_directories(Kaiju/Knowledge)
include_directories(Kaiju/Monitor)
include_directories(Kaiju/Plan)
include_directories(Kaiju/Robot)
include_directories(Kaiju/Sensors)
include_directories(Kaiju/Util)
include_directories(robotnik_avoid_wall/Actuators)
include_directories(robotnik_avoid_wall/Analyze)
include_directories(robotnik_avoid_wall/Connection)
include_directories(robotnik_avoid_wall/Execute/Actions)
include_directories(robotnik_avoid_wall/Knowledge)
include_directories(robotnik_avoid_wall/Monitor)
include_directories(robotnik_avoid_wall/P3DXConnection)
include_directories(robotnik_avoid_wall/Plan)
include_directories(robotnik_avoid_wall/Robot)
include_directories(robotnik_avoid_wall/Sensors)

set(SOURCES
        robotnik_avoid_wall/Actuators/robotnik_wheel_vrep.cpp
        robotnik_avoid_wall/Actuators/robotnik_wheel_vrep.h
        robotnik_avoid_wall/Actuators/wheel_vrep.cpp
        robotnik_avoid_wall/Actuators/wheel_vrep.h
        robotnik_avoid_wall/Analyze/pass_vrep_orientation.cpp
        robotnik_avoid_wall/Analyze/pass_vrep_orientation.h
        robotnik_avoid_wall/Analyze/pass_vrep_position.cpp
        robotnik_avoid_wall/Analyze/pass_vrep_position.h
        robotnik_avoid_wall/Analyze/pass_vrep_range.cpp
        robotnik_avoid_wall/Analyze/pass_vrep_range.h
        robotnik_avoid_wall/Connection/connection.cpp
        robotnik_avoid_wall/Connection/connection.h
        robotnik_avoid_wall/Execute/Actions/go_to_position.cpp
        robotnik_avoid_wall/Execute/Actions/go_to_position.h
        robotnik_avoid_wall/Execute/Actions/set_wheels_speed.cpp
        robotnik_avoid_wall/Execute/Actions/set_wheels_speed.h
        robotnik_avoid_wall/Execute/Actions/turn_to_angle.cpp
        robotnik_avoid_wall/Execute/Actions/turn_to_angle.h
        robotnik_avoid_wall/Knowledge/robotnik_knowledge.cpp
        robotnik_avoid_wall/Knowledge/robotnik_knowledge.h
        robotnik_avoid_wall/Knowledge/avoid_wall_model.h
        robotnik_avoid_wall/Knowledge/avoid_wall_model.cpp
        robotnik_avoid_wall/Knowledge/robotnik_model.cpp
        robotnik_avoid_wall/Knowledge/robotnik_model.h
        robotnik_avoid_wall/Monitor/orientation_vrep_monitor.cpp
        robotnik_avoid_wall/Monitor/orientation_vrep_monitor.h
        robotnik_avoid_wall/Monitor/position_vrep_monitor.cpp
        robotnik_avoid_wall/Monitor/position_vrep_monitor.h
        robotnik_avoid_wall/Monitor/range_vrep_monitor.cpp
        robotnik_avoid_wall/Monitor/range_vrep_monitor.h
        robotnik_avoid_wall/Plan/go_to_origin_planner.cpp
        robotnik_avoid_wall/Plan/go_to_origin_planner.h
        robotnik_avoid_wall/Robot/robotnik.cpp
        robotnik_avoid_wall/Robot/robotnik.h
        robotnik_avoid_wall/Sensors/orientation_vrep_sensor.cpp
        robotnik_avoid_wall/Sensors/orientation_vrep_sensor.h
        robotnik_avoid_wall/Sensors/position_vrep_sensor.cpp
        robotnik_avoid_wall/Sensors/position_vrep_sensor.h
        robotnik_avoid_wall/Sensors/range_vrep_sensor.cpp
        robotnik_avoid_wall/Sensors/range_vrep_sensor.h

        main.cpp robotnik_avoid_wall/Sensors/P3DXPositionSensor.cpp
        robotnik_avoid_wall/Sensors/P3DXPositionSensor.h
        robotnik_avoid_wall/Monitor/P3DXPositionMonitor.cpp
        robotnik_avoid_wall/Monitor/P3DXPositionMonitor.h
        robotnik_avoid_wall/Analyze/PassP3DXPosition.cpp
        robotnik_avoid_wall/Analyze/PassP3DXPosition.h

        robotnik_avoid_wall/Visualizer/file_visualizer.h
        robotnik_avoid_wall/Visualizer/file_visualizer.cpp
        )


find_package(Threads)

add_executable(robotnik_follow ${SOURCES})

target_link_libraries(robotnik_follow ${CMAKE_THREAD_LIBS_INIT} remote_api pthread)

install(TARGETS robotnik_follow RUNTIME DESTINATION bin)
