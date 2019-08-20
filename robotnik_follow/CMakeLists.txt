cmake_minimum_required(VERSION 3.13)
project(robotnik_follow)

INCLUDE(FindPkgConfig)

include_directories(remote_api_vrep ../FRoCS)

add_subdirectory(../remote_api_vrep build)

set(CMAKE_CXX_STANDARD 17)
IF (CMAKE_COMPILER_IS_GNUCC)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -DBUILD_SHARED_LIBS=OFF -lpthread")
ENDIF (CMAKE_COMPILER_IS_GNUCC)

include_directories(FRoCS)

set(SOURCES
        Actuators/robotnik_wheel_vrep.cpp
        Actuators/robotnik_wheel_vrep.h
        Actuators/wheel_vrep.cpp
        Actuators/wheel_vrep.h
        Analyze/pass_vrep_orientation.cpp
        Analyze/pass_vrep_orientation.h
        Analyze/pass_vrep_position.cpp
        Analyze/pass_vrep_position.h
        Analyze/pass_vrep_range.cpp
        Analyze/pass_vrep_range.h
        Connection/connection.cpp
        Connection/connection.h
        Execute/Actions/go_to_position.cpp
        Execute/Actions/go_to_position.h
        Execute/Actions/set_wheels_speed.cpp
        Execute/Actions/set_wheels_speed.h
        Execute/Actions/turn_to_angle.cpp
        Execute/Actions/turn_to_angle.h
        Knowledge/robotnik_knowledge.cpp
        Knowledge/robotnik_knowledge.h
        Knowledge/avoid_wall_model.h
        Knowledge/avoid_wall_model.cpp
        Knowledge/robotnik_model.cpp
        Knowledge/robotnik_model.h
        Monitor/orientation_vrep_monitor.cpp
        Monitor/orientation_vrep_monitor.h
        Monitor/position_vrep_monitor.cpp
        Monitor/position_vrep_monitor.h
        Monitor/range_vrep_monitor.cpp
        Monitor/range_vrep_monitor.h
        Plan/go_to_origin_planner.cpp
        Plan/go_to_origin_planner.h
        Robot/robotnik.cpp
        Robot/robotnik.h
        Sensors/orientation_vrep_sensor.cpp
        Sensors/orientation_vrep_sensor.h
        Sensors/position_vrep_sensor.cpp
        Sensors/position_vrep_sensor.h
        Sensors/range_vrep_sensor.cpp
        Sensors/range_vrep_sensor.h

        main.cpp Sensors/P3DXPositionSensor.cpp
        Sensors/P3DXPositionSensor.h
        Monitor/P3DXPositionMonitor.cpp
        Monitor/P3DXPositionMonitor.h
        Analyze/pass_robotnik_position.cpp
        Analyze/pass_robotnik_position.h

        Visualizer/file_visualizer.h
        Visualizer/file_visualizer.cpp
        )

find_package(Threads)

add_executable(robotnik_follow ${SOURCES})

target_link_libraries(robotnik_follow ${CMAKE_THREAD_LIBS_INIT} remote_api pthread)

install(TARGETS robotnik_follow RUNTIME DESTINATION bin)
