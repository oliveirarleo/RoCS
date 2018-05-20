//
// Created by kaiju on 15/05/18.
//

#include "pioneer_p3dx_model.h"

#include <iostream>

extern "C"
{
#include "v_repConst.h"
}


PioneerP3DXModel::PioneerP3DXModel():	robot_name{"Pioneer_p3dx"},
																			 robot_handle{-1},
																			 connection{},
																			 robot_position{},
																			 sonars{}
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

		connectToSonars();
		connectToWheels();
	}
	else
	{
		std::cout << "Not connected to robot: " << robot_name << std::endl;
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

const std::vector<SonarVREP> &PioneerP3DXModel::getSonars() const
{
	return sonars;
}

const std::vector<WheelVREP> &PioneerP3DXModel::getWheels() const
{
	return wheels;
}
