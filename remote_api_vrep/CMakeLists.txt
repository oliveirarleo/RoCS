cmake_minimum_required(VERSION 3.1)

include(FindPkgConfig)

set(CMAKE_CXX_STANDARD 17)
#IF (CMAKE_COMPILER_IS_GNUCC)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -DBUILD_SHARED_LIBS=OFF")
#ENDIF (CMAKE_COMPILER_IS_GNUCC)

# definicoes da remoteAPI para CPP
add_definitions(-DNON_MATLAB_PARSING -DMAX_EXT_API_CONNECTIONS=255 -DDO_NOT_USE_SHARED_MEMORY -DBUILD_SHARED_LIBS=OFF -DCMAKE_OSX_ARCHITECTURES=x86_64)

set(SOURCES
        remoteApi/extApi.c
        remoteApi/extApiPlatform.c
        )

set(HEADERS
        remoteApi/extApi.h
        remoteApi/extApiInternal.h
        remoteApi/extApiPlatform.h
        include/v_repConst.h
        include/v_repLib.h
        )

include_directories("include")
include_directories("remoteApi")

add_library(remote_api ${SOURCES} ${HEADERS})

