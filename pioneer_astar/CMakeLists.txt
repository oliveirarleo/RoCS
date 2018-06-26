cmake_minimum_required(VERSION 3.9)
project(Pioneer)

INCLUDE(FindPkgConfig)

#include_directories ("src/Kaiju")
#include_directories ("src/Pioneer_p3dx")
add_subdirectory(remote_api_vrep)

include_directories(remote_api_vrep Kaiju)


set(CMAKE_CXX_STANDARD 17)
IF (CMAKE_COMPILER_IS_GNUCC)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -DBUILD_SHARED_LIBS=OFF -lpthread")
ENDIF (CMAKE_COMPILER_IS_GNUCC)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -DBUILD_SHARED_LIBS=OFF")
# set(CMAKE_VERBOSE_MAKEFILE ON)

set(ARCH_SOURCES
        Kaiju/Sensors/sensor.h
        Kaiju/Sensors/range.h
        Kaiju/Sensors/sonar.h
        Kaiju/Actuators/actuator.h
        Kaiju/Actuators/rotary_motor.h
        Kaiju/Monitor/monitor.h
        Kaiju/Analyze/analyze.h
        Kaiju/Plan/planner.h
        Kaiju/Execute/execute.h
        Kaiju/Execute/action.h
        Kaiju/Knowledge/robot_model.h
        Kaiju/Knowledge/position.h
        Kaiju/Util/publisher.h
        Kaiju/Util/observer.h
        Kaiju/Util/pipeline.h)

set(HEADERS
        ${ARCH_SOURCES}
        PioneerP3DX/AStarPioneer/a_star_pioneer.h
        PioneerP3DX/Knowledge/pioneer_p3dx_model.h
        PioneerP3DX/Connection/connection.h
        PioneerP3DX/Sensors/sonar_vrep.h
        PioneerP3DX/Actuators/wheel_vrep.h
        PioneerP3DX/Monitor/sonar_vrep_monitor.h
        PioneerP3DX/Analyze/pass_sonar_position.h
        PioneerP3DX/Plan/brait_plan.h
        PioneerP3DX/Sensors/sonar_output.h
        PioneerP3DX/Execute/execute_p3dx.h
        PioneerP3DX/Execute/Actions/move_wheels.h
        )

set(SOURCES
        main.cpp
        PioneerP3DX/AStarPioneer/a_star_pioneer.cpp
        PioneerP3DX/Knowledge/pioneer_p3dx_model.cpp
        PioneerP3DX/Connection/connection.cpp
        PioneerP3DX/Sensors/sonar_vrep.cpp
        PioneerP3DX/Actuators/wheel_vrep.cpp
        PioneerP3DX/Monitor/sonar_vrep_monitor.cpp
        PioneerP3DX/Analyze/pass_sonar_position.cpp
        PioneerP3DX/Plan/brait_plan.cpp
        PioneerP3DX/Execute/Actions/move_wheels.cpp Kaiju/Util/pipeline.cpp)

find_package(Threads)

add_executable(Pioneer ${SOURCES} ${HEADERS})

target_link_libraries(Pioneer ${CMAKE_THREAD_LIBS_INIT} remote_api pthread)

install(TARGETS Pioneer RUNTIME DESTINATION bin)
