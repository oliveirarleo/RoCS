//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include <include/v_repConst.h>

#include <utility>
#include <iostream>
#include <Knowledge/knowledge.h>

#include "wheel_vrep.h"

WheelVREP::WheelVREP(std::string name_, Connection &connection_)
	:RotaryMotor(std::move(name_)), handle(-1), connection(connection_)
{
	int id = connection.getClientId();

	if (simxGetObjectHandle(id, (const simxChar *) name.c_str(), (simxInt *) &handle,
	                        (simxInt) simx_opmode_oneshot_wait) != simx_return_ok)
		std::cout << "Handle do motor" << name << " nao encontrado! " << " Handle:" << handle << std::endl;
	else
	{
		std::cout << "Conectado ao motor" << name << " Handle:" << handle << std::endl;
		setSpeed(0);
	}
}

void WheelVREP::setSpeed(double speed)
{
	simxSetJointTargetVelocity(connection.getClientId(), handle, (simxFloat) speed, simx_opmode_streaming);
}
