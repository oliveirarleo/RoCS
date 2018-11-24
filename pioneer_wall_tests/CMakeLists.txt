cmake_minimum_required(VERSION 3.9)
project(Pioneer)

INCLUDE(FindPkgConfig)

#add_subdirectory(remote_api_vrep)

include_directories(remote_api_vrep Kaiju)


set(CMAKE_CXX_STANDARD 17)
IF (CMAKE_COMPILER_IS_GNUCC)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -DBUILD_SHARED_LIBS=OFF -lpthread")
ENDIF (CMAKE_COMPILER_IS_GNUCC)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -DBUILD_SHARED_LIBS=OFF")
# set(CMAKE_VERBOSE_MAKEFILE ON)

set(ARCH_SOURCES
#        Kaiju/Knowledge/robot_model.h
#        Kaiju/Knowledge/reactive_model.h
#        Kaiju/Knowledge/strategy_model.h
#        Kaiju/Knowledge/world_model.h
#        Kaiju/Knowledge/knowledge.h

#        Kaiju/Robot/robot.h
#
#        Kaiju/Sensors/sensor.h
#
#        Kaiju/Actuators/actuator.h
#
#        Kaiju/Monitor/monitor.h
#        Kaiju/Analyze/analyze.h
#        Kaiju/Plan/planner.h
#        Kaiju/Execute/execute.h
#        Kaiju/Execute/action.h
#
#        Kaiju/Util/publisher.h
#        Kaiju/Util/observer.h
#        Kaiju/Util/pipeline.h
#        Kaiju/Util/position.h
#        Kaiju/Util/orientation.h


        )

set(HEADERS
        ${ARCH_SOURCES}
#        pioneer_p3dx_avoid_wall/Robot/pioneer_p3dx.h

#        ./pioneer_p3dx_avoid_wall/Actuators/wheel_vrep.h
#        pioneer_p3dx_avoid_wall/Knowledge/p3dx_knowledge.h
#        pioneer_p3dx_avoid_wall/Knowledge/pioneer_p3dx_model.h
#        pioneer_p3dx_avoid_wall/Knowledge/avoid_wall_model.h
        )

set(SOURCES
        pioneer_p3dx_avoid_wall/Robot/pioneer_p3dx.cpp
        main.cpp



#        pioneer_p3dx_avoid_wall/Actuators/wheel_vrep.cpp
#        pioneer_p3dx_avoid_wall/Knowledge/p3dx_knowledge.cpp
#        pioneer_p3dx_avoid_wall/Knowledge/pioneer_p3dx_model.cpp
#        pioneer_p3dx_avoid_wall/Knowledge/avoid_wall_model.cpp
#
        )

find_package(Threads)

add_executable(Pioneer ${SOURCES})

target_link_libraries(Pioneer ${CMAKE_THREAD_LIBS_INIT} remote_api pthread)

install(TARGETS Pioneer RUNTIME DESTINATION bin)
