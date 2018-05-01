cmake_minimum_required(VERSION 3.9)

INCLUDE(FindPkgConfig)

IF(CMAKE_COMPILER_IS_GNUCC)
    SET(CMAKE_CXX_FLAGS
            "${CMAKE_CXX_FLAGS} -Wall -std=c++0x -DBUILD_SHARED_LIBS=OFF")
ENDIF(CMAKE_COMPILER_IS_GNUCC)

# definicoes da remoteAPI para CPP
add_definitions(-DNON_MATLAB_PARSING -DMAX_EXT_API_CONNECTIONS=255 -DDO_NOT_USE_SHARED_MEMORY)

set(SOURCES
        remoteApi/extApi.c
        #remoteApi/extApiCustom.c
        remoteApi/extApiPlatform.c
        )

set(HEADERS
        remoteApi/extApi.h
        #remoteApi/extApiCustom.h
        remoteApi/extApiInternal.h
        remoteApi/extApiPlatform.h
        include/v_repConst.h
        include/v_repLib.h
        )
include_directories("include/")
include_directories("remoteApi/")

find_package (Threads)

#add_executable(cppremoteapi
#        ${SOURCES}
#        ${HEADERS})

add_library(remote_api ${SOURCES})

