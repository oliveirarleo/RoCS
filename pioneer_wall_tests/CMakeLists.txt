cmake_minimum_required(VERSION 3.1)

project(pioneer_xwalk)

include(FindPkgConfig)

include_directories(../remote_api_vrep ../FRoCS)

add_subdirectory(../remote_api_vrep build)

IF (CMAKE_COMPILER_IS_GNUCC)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
ENDIF (CMAKE_COMPILER_IS_GNUCC)

file(GLOB SOURCES "./*/*.cpp"  "./*/*/*.cpp" main.cpp)

file(GLOB HEADERS "./*/*/*.h" "./*/*.h")

find_package(Threads)

add_executable(pioneer_xwalk ${HEADERS} ${SOURCES})

target_link_libraries(pioneer_xwalk  ${CMAKE_THREAD_LIBS_INIT} remote_api pthread)

install(TARGETS pioneer_xwalk RUNTIME DESTINATION bin)
