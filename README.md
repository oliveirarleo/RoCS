# RoCS
Laboratory of robotics and cognitive systems

# Author
Leonardo de Oliveira Ramos

# Description
This framework is an instance of the RoCS Architecture.

# Instructions

These instructions were tested in Arch Linux, Fedora 23 and MacOS

- Make sure you have VREP, cmake and make installed.
- To compile, execute the compile_pioneer_and_robotnik.sh script
- Change the remoteApiConnections.txt file in VREP directory and make sure it has the following lines:

```
portIndex1_port             = 19997
portIndex1_debug            = false
portIndex1_syncSimTrigger   = true

portIndex2_port             = 19998
portIndex2_debug            = false
portIndex2_syncSimTrigger   = true
```

- Open VREP and load the scene ./vrep/scene_02.ttt
- Start the simulation pressing the play button
- To execute the code for the Pioneer run ./pioneer_wall_tests/cmake-build-debug/pioneer_xwalk
- To execute the code for the Robotnik run ./robotnik_follow/cmake-build-debug/robotnik_follow

