#! /bin/bash

cd pioneer_wall_tests
[[ -d cmake-build-debug ]] || mkdir cmake-build-debug
cd cmake-build-debug
cmake ..
make

cd ./../../

cd robotnik_follow
[[ -d cmake-build-debug ]] || mkdir cmake-build-debug
cd cmake-build-debug
cmake ..
make