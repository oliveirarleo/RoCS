//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include "pioneer_p3dx_model.h"

#include <iostream>

PioneerP3DXModel::PioneerP3DXModel()
	:RobotModel("Pioneer_p3dx"), robot_position{}, robot_orientation{}
{

}


Position PioneerP3DXModel::getPosition()
{
	if(!Observer<std::vector<Position> >::observed_value.empty())
		return Observer<std::vector<Position> >::observed_value[0];
	else
		return Position();
}

Orientation PioneerP3DXModel::getOrientation()
{
	if(!Observer<std::vector<Orientation> >::observed_value.empty())
		return Observer<std::vector<Orientation> >::observed_value[0];
	else
		return Orientation();
}

//Position &PioneerP3DXModel::getRobotPosition()
//{
//	float pos[3];
//	simxGetObjectPosition(connection.getClientId(), robot_handle, -1, pos, simx_opmode_streaming);
//	robot_position.setPosition((double) pos[0], (double) pos[1], (double) pos[2]);
//
//	std::cout << robot_position << std::endl;
//
//	return robot_position;
//}
