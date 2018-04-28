//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include "pioneer_p_3_dx.h"

#include <iostream>

extern "C"
{
}

//#include "../Connection/connection.h"

class connection;

Pioneer_p3dx::Pioneer_p3dx(std::string &name) : robot_name(name)
{
	//	Connect to server via ip and
	verifyConnection();

	getRobotInfo();

	instantiateSensors();

	instantiateActuators();
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

void Pioneer_p3dx::instantiateSensors()
{
	std::string ultra_sonic_name = "Pioneer_p3dx_ultrasonicSensor";

	for (int sensor_num = 1; sensor_num <= 16; ++sensor_num)
	{
		std::string sensor_name = ultra_sonic_name + std::to_string(sensor_num);
		Position p{1, 2, 3};
		SonarVREP s{sensor_name, connection, this, 0, p, 0, 0, 0, 0, 0, 0};
		range_sensors.push_back(s);
	}

}

void Pioneer_p3dx::instantiateActuators()
{

}

int Pioneer_p3dx::getHandle()
{
	return robot_handle;
}
