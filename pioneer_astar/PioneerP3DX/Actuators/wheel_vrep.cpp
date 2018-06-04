//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include <include/v_repConst.h>

#include <utility>
#include "wheel_vrep.h"
#include "../Knowledge/pioneer_p3dx_model.h"

WheelVREP::WheelVREP(const std::string &name_, RobotModel &robot_)
				: RotaryMotor(name_), handle(-1), robot(robot_),
					connection(const_cast<Connection &>(((PioneerP3DXModel &) robot_).getConnection()))
{
}

void WheelVREP::setName(std::string name_)
{
	name = std::move(name_);
}

void WheelVREP::setSpeed(double speed)
{
	simxSetJointTargetVelocity(((PioneerP3DXModel &) robot).getConnection().getClientId(), handle, (simxFloat) speed,
														 simx_opmode_streaming);
}
