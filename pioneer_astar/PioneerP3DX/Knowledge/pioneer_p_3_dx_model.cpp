//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//
#include "pioneer_p_3_dx_model.h"

#include <iostream>

extern "C"
{
#include <include/v_repConst.h>
}



PioneerP3DXModel::PioneerP3DXModel() : robot_name{"Pioneer_p3dx"}, robot_handle{-1}, connection{}, robot_position{},
																			 sonars{}
{
	verifyConnection();
	connectToRobot();
}


void PioneerP3DXModel::verifyConnection()
{
	if (connection.isConnected())
	{
		std::cout << "Connected to client: " << connection.getClientId() << std::endl;
	}
	else
	{
		std::cout << "Could not connect to client" << std::endl;
		exit(1);
	}
}



void PioneerP3DXModel::connectToRobot()
{
	if (simxGetObjectHandle(connection.getClientId(), (const simxChar *) robot_name.c_str(), (simxInt *) &robot_handle,
													(simxInt) simx_opmode_oneshot_wait) == simx_return_ok)
	{
		std::cout << "Connected to robot: " << robot_name << std::endl;

		connectToSonars();
		connectToWheels();
	}
	else
	{
		std::cout << "Could not connect to robot: " << robot_name << std::endl;
		exit(1);
	}
}

void PioneerP3DXModel::connectToSonars()
{
	for (int num_sonars = 1; num_sonars <= 16; ++num_sonars)
	{
		std::string sonar_name = "Pioneer_p3dx_ultrasonicSensor" + std::to_string(num_sonars);
		SonarVREP sonar{sonar_name, *this};
		sonars.push_back(sonar);
	}
}

void PioneerP3DXModel::connectToWheels()
{
	std::string left_wheel_name = "Pioneer_p3dx_leftMotor";
	WheelVREP left_wheel{left_wheel_name, *this};
	wheels.push_back(left_wheel);

	std::string right_wheel_name = "Pioneer_p3dx_rightMotor";
	WheelVREP right_wheel{right_wheel_name, *this};
	wheels.push_back(right_wheel);
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

const Position &PioneerP3DXModel::getRobotPosition()
{
	float pos[3];
	simxGetObjectPosition(connection.getClientId(), robot_handle, -1, pos, simx_opmode_streaming);
	robot_position.setPosition((double) pos[0], (double) pos[1], (double) pos[2]);

	std::cout << robot_position << std::endl;

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

const std::vector<SonarVREP> &PioneerP3DXModel::getSonars() const
{
	return sonars;
}

const std::vector<WheelVREP> &PioneerP3DXModel::getWheels() const
{
	return wheels;
}