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
#include "../PioneerP3DX/pioneer_p3dx.h"

WheelVREP::WheelVREP(std::string name_, Knowledge &knowledge_) : RotaryMotor(std::move(name_)), handle(-1),
																																 knowledge(knowledge_),
																																 connection(
																																	 const_cast<Connection &>(((P3DXKnowledge &) knowledge_).getConnection()))
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
	simxSetJointTargetVelocity(((P3DXKnowledge &) knowledge).getConnection().getClientId(), handle, (simxFloat) speed,
														 simx_opmode_streaming);
}
