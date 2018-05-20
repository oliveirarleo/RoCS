//
// Created by kaiju on 15/05/18.
//

#include "wheel_vrep.h"

#include <iostream>

extern "C" {
#include "extApi.h"
#include "v_repConst.h"
}

#include "../Knowledge/pioneer_p3dx_model.h"

//WheelVREP::WheelVREP()
//{
//}

WheelVREP::WheelVREP(std::string name_, RobotModel &robot_)
	: RotaryMotor(name_), robot(robot_), handle{0},
		connection(const_cast<Connection &>(((PioneerP3DXModel &) robot_).getConnection()))
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


WheelVREP::WheelVREP(std::string name_, RobotModel &robot_, Connection &connection)
	: RotaryMotor(name_), robot(robot_), handle{0}, connection(connection)
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


void WheelVREP::setName(std::string name_)
{
	name = name_;
}

void WheelVREP::setSpeed(double speed)
{
	simxSetJointTargetVelocity(((PioneerP3DXModel &) robot).getConnection().getClientId(), handle, (simxFloat) speed,
														 simx_opmode_streaming);
}