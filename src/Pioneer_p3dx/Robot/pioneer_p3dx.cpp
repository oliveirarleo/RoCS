//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include "pioneer_p3dx.h"

#include <iostream>

extern "C"
{
#include "extApi.h"
#include "v_repConst.h"
}

#include "../Connection/connection.h"

Pioneer_p3dx::Pioneer_p3dx() : is_connected{false},
															 robot_name{"Pioneer_p3dx"},
															 robot_position{0, 0, 0},
															 robot_handle{-1},
															 connection{}
{
	//	Connect to server via ip and
	verifyConnection();

	getRobotInfo();

}

void Pioneer_p3dx::verifyConnection()
{
	using namespace std;

	if (connection.isConnected())
	{
		cout << "Connected to client: " << connection.getClientId() << endl;
	}
	else
	{
		cout << "Not connected to client" << endl;
	}
}

void Pioneer_p3dx::getRobotPosition()
{
	float pos[3];
	simxGetObjectPosition(connection.getClientId(), robot_handle, -1, pos, simx_opmode_streaming);
	robot_position.setPosition((double) pos[0], (double) pos[1], (double) pos[2]);
}

void Pioneer_p3dx::getRobotInfo()
{
	if (simxGetObjectHandle(connection.getClientId(), (const simxChar *) robot_name.c_str(), (simxInt *) &robot_handle,
													(simxInt) simx_opmode_oneshot_wait) == simx_return_ok)
	{
		is_connected = true;
		std::cout << "Connected to robot: " << robot_name << std::endl;

		getRobotPosition();
	}
	else
	{
		std::cout << "Not connected to robot: " << robot_name << std::endl;
	}
}

int Pioneer_p3dx::getHandle()
{
	return robot_handle;
}
