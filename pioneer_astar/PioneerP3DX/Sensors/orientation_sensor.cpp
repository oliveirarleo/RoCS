//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include <include/v_repConst.h>
#include <remoteApi/extApi.h>
#include <iostream>
#include "orientation_sensor.h"
#include "../Knowledge/pioneer_p3dx_model.h"

OrientationSensor::OrientationSensor(const std::string name_, RobotModel &robot_)
				: Sensor(name_), handle(((PioneerP3DXModel &) robot_).getHandle()), robot(robot_),
					connection(const_cast<Connection &>(((PioneerP3DXModel &) robot_).getConnection()))
{
	float angle[3] = {5,6,7};

	std::cout << connection.getClientId()<< " " << handle << " "<< simxGetObjectOrientation(connection.getClientId(), 32, -1, angle, simx_opmode_streaming) << std::endl;
	std::cout << angle[0]<< angle[1]<< angle[2] << std::endl;
	std::cout << connection.getClientId()<< " " << handle << " "<< simxGetObjectOrientation(connection.getClientId(), handle, -1, angle, simx_opmode_streaming) << std::endl;
	std::cout << angle[0]<< angle[1]<< angle[2] << std::endl;
	std::cout << connection.getClientId()<< " " << handle << " "<< simxGetObjectPosition( connection.getClientId(), handle,-1, angle,simx_opmode_streaming) << std::endl;
	std::cout << angle[0]<< angle[1]<< angle[2] << std::endl;
	if (simxGetObjectOrientation(connection.getClientId(), handle, -1, nullptr, simx_opmode_buffer) == simx_return_ok)
	{
		float angle[3];
		simxGetObjectOrientation(connection.getClientId(), handle, -1, angle, simx_opmode_buffer);
		std::cout << "Connected to sensor " << name << " Handle: " << handle << "Angle: " << angle << std::endl;
	}
	else
	{
		std::cout << "Not connected to sensor " << name << std::endl;
	}

}

bool OrientationSensor::getData(EulerAngle &value)
{
	float angle[3];
	if (simx_return_ok == simxGetObjectOrientation(connection.getClientId(), handle, -1, angle, simx_opmode_buffer))
	{
		value.setEulerAngle(angle[0], angle[1], angle[2]);
		return true;
	}


	return false;
}


