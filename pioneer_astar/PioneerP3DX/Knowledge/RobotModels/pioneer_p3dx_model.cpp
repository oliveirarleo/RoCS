//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//
#include "pioneer_p3dx_model.h"

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
		std::cout << "Connected to robot: " << robot_name << " handle: " << robot_handle << std::endl;
		connectToPositionSensor();
		connectToSonars();
		connectToOrientationSensor();
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
		sonars.push_back(new RangeVREP{sonar_name, *this});
	}
}

void PioneerP3DXModel::connectToOrientationSensor()
{
	orientation_sensor = new OrientationVREPSensor("OrientationVREPSensor", *this);
	orientation_sensor->getData(robot_orientation);
}

void PioneerP3DXModel::connectToPositionSensor()
{
	position_sensor = new PositionVREPSensor{"PositionSensor", *this};
	position_sensor->getData(robot_position);
	std::cout << "First Pos: " << robot_position << std::endl;
}

void PioneerP3DXModel::connectToWheels()
{
	std::string left_wheel_name = "Pioneer_p3dx_leftMotor";
	wheels.push_back(new WheelVREP{left_wheel_name, *this});

	std::string right_wheel_name = "Pioneer_p3dx_rightMotor";
	wheels.push_back(new WheelVREP{right_wheel_name, *this});
}

//
// Get methods
//
int PioneerP3DXModel::getHandle()
{
	return robot_handle;
}

std::string &PioneerP3DXModel::getRobotName()
{
	return robot_name;
}

Position &PioneerP3DXModel::getRobotPosition()
{
	float pos[3];
	simxGetObjectPosition(connection.getClientId(), robot_handle, -1, pos, simx_opmode_streaming);
	robot_position.setPosition((double) pos[0], (double) pos[1], (double) pos[2]);

	std::cout << robot_position << std::endl;

	return robot_position;
}


int PioneerP3DXModel::getRobotHandle()
{
	return robot_handle;
}

Connection &PioneerP3DXModel::getConnection()
{
	return connection;
}

std::vector<RangeVREP *> &PioneerP3DXModel::getSonars()
{
	return sonars;
}

OrientationVREPSensor *PioneerP3DXModel::getOrientationSensor()
{
	return orientation_sensor;
}

PositionVREPSensor *PioneerP3DXModel::getPositionSensor()
{
	return position_sensor;
}

std::vector<WheelVREP *> &PioneerP3DXModel::getWheels()
{
	return wheels;
}