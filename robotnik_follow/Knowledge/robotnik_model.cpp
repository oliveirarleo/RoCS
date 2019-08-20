//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include "robotnik_model.h"

#include <iostream>

RobotnikModel::RobotnikModel()
	:RobotModel("Robotnik_Summit_XL"), robot_position{}, robot_orientation{}
{

}



Position RobotnikModel::getRobotPosition()
{
    if(!Observer<std::vector<Position> >::observed_value.empty()){
        robot_position = Observer<std::vector<Position> >::observed_value[0];
        return robot_position;
    }
    else
        return Position();
}

Orientation RobotnikModel::getRobotOrientation()
{
    if(!Observer<std::vector<Orientation> >::observed_value.empty()){

        robot_orientation = Observer<std::vector<Orientation> >::observed_value[0];
        return robot_orientation;
    }
    else
        return Orientation();
}



//Position &RobotnikModel::getRobotPosition()
//{
//	float pos[3];
//	simxGetObjectPosition(connection.getClientId(), robot_handle, -1, pos, simx_opmode_streaming);
//	robot_position.setPosition((double) pos[0], (double) pos[1], (double) pos[2]);
//
//	std::cout << robot_position << std::endl;
//
//	return robot_position;
//}
