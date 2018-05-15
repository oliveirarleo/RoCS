//
// Created by kaiju on 15/05/18.
//

#include "pioneer_p3dx_model.h"

#include <iostream>

extern "C"
{
#include "extApi.h"
#include "v_repConst.h"
}


PioneerP3DXModel::PioneerP3DXModel():	robot_name{"Pioneer_p3dx"},
																			robot_handle{-1},
																			connection{},
																			 robot_position{0, 0, 0}
{
}



void PioneerP3DXModel::verifyConnection()
{
	if (connection.isConnected())
	{
		std::cout << "Connected to client: " << connection.getClientId() << std::endl;
	}
	else
	{
		std::cout << "Not connected to client" << std::endl;
		exit(1);
	}
}


void PioneerP3DXModel::connectToRobot()
{
	if (simxGetObjectHandle(connection.getClientId(), (const simxChar *) robot_name.c_str(), (simxInt *) &robot_handle,
													(simxInt) simx_opmode_oneshot_wait) == simx_return_ok)
	{
		std::cout << "Connected to robot: " << robot_name << std::endl;
	}
	else
	{
		std::cout << "Not connected to robot: " << robot_name << std::endl;
	}
}

//
// Get methods
//

int PioneerP3DXModel::getHandle()
{
	return robot_handle;
}

const std::string &PioneerP3DXModel::getRobotName() const
{
	return robot_name;
}

const Position &PioneerP3DXModel::getRobotPosition() const
{
	return robot_position;
}

int PioneerP3DXModel::getRobotHandle() const
{
	return robot_handle;
}

const Connection &PioneerP3DXModel::getConnection() const
{
	return connection;
}
