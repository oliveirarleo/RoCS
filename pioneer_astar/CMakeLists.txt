cmake_minimum_required(VERSION 3.9)
project(Pioneer)

INCLUDE(FindPkgConfig)

#include_directories ("src/Kaiju")
#include_directories ("src/Pioneer_p3dx")
add_subdirectory(remote_api_vrep)

include_directories(remote_api_vrep Kaiju)


set(CMAKE_CXX_STANDARD 17)
IF (CMAKE_COMPILER_IS_GNUCC)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -DBUILD_SHARED_LIBS=OFF ")
ENDIF (CMAKE_COMPILER_IS_GNUCC)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -DBUILD_SHARED_LIBS=OFF")
# set(CMAKE_VERBOSE_MAKEFILE ON)

set(HEADERS
        Kaiju/Sensors/sensor.h
        Kaiju/Sensors/sensor_accessor.h
        Kaiju/Sensors/range.h
        Kaiju/Sensors/sonar.h
        Kaiju/Actuators/actuator_accessor.h
        Kaiju/Actuators/actuator.h
        Kaiju/Actuators/rotary_motor.h
        Kaiju/Monitor/monitor.h
        Kaiju/Analyze/analyze.h
        Kaiju/Knowledge/robot_model.h)

set(ARCH_SOURCES
        )

set(SOURCES
        ${ARCH_SOURCES}
        main.cpp PioneerP3DX/AStarPioneer/a_star_pioneer.cpp PioneerP3DX/AStarPioneer/a_star_pioneer.h PioneerP3DX/Knowledge/pioneer_p_3_dx_model.cpp PioneerP3DX/Knowledge/pioneer_p_3_dx_model.h PioneerP3DX/Connection/connection.cpp PioneerP3DX/Connection/connection.h PioneerP3DX/Sensors/sonar_vrep.cpp PioneerP3DX/Sensors/sonar_vrep.h PioneerP3DX/Actuators/wheel_vrep.cpp PioneerP3DX/Actuators/wheel_vrep.h)

find_package(Threads)

add_executable(Pioneer ${SOURCES} ${HEADERS})

target_link_libraries(Pioneer ${CMAKE_THREAD_LIBS_INIT} remote_api pthread)

install(TARGETS Pioneer RUNTIME DESTINATION bin)
