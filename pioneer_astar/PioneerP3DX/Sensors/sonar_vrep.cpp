//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include "sonar_vrep.h"

#include <iostream>

extern "C"
{
#include <remoteApi/extApi.h>
#include <include/v_repConst.h>
}

#include "../Knowledge/pioneer_p3dx_model.h"

SonarVREP::SonarVREP(const std::string &name_, RobotModel &robot_)
				: Range(name_), robot(robot_), handle(-1),
					connection(const_cast<Connection &>(((PioneerP3DXModel &) robot_).getConnection()))
{
	while (handle == -1)
	{
		if (simxGetObjectHandle(connection.getClientId(), (const simxChar *) name.c_str(), (simxInt *) &handle,
														(simxInt) simx_opmode_oneshot_wait) == simx_return_ok)
		{
			simxReadProximitySensor(connection.getClientId(), handle, NULL, NULL, NULL, NULL, simx_opmode_streaming);
			std::cout << "Connected to sensor " << name << " Handle: " << handle << std::endl;
		}
		else
		{
			std::cout << "Not connected to sensor " << name << std::endl;
		}
	}


}


bool SonarVREP::getData(SonarOutput &position)
{
	float point[3];
	char state;
	if ((simxReadProximitySensor(connection.getClientId(), handle, (simxUChar *) &state, point, nullptr, nullptr,
															 simx_opmode_buffer) == simx_return_ok) && (state > 0))
	{
		position.setSonarOutput((double) point[0], (double) point[1], (double) point[2], state);
		return true;
	}
//	std::cout << point[0] << point[1]<< point[2]<< std::endl;
	return false;
}

bool SonarVREP::getData(SonarOutput &position, char &state)
{
	float point[3];
	if (simxReadProximitySensor(connection.getClientId(), handle, (simxUChar *) &state, point,
															nullptr, nullptr, simx_opmode_buffer) == simx_return_ok)
	{
		position.setPosition((double) point[0], (double) point[1], (double) point[2]);
//		std::cout << position << std::endl;
		return true;
	}
//	std::cout << point[0] << point[1]<< point[2]<< std::endl;
	return false;
}

int SonarVREP::getHandle() const
{
	return handle;
}
