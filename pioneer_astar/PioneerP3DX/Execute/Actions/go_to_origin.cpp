//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include <iostream>
#include "go_to_origin.h"
#include "turn_angle.h"
#include "turn_to_angle.h"
#include "../../Analyze/pass_orientation.h"
#include "set_wheel_speed.h"

void GoToOrigin::act()
{
//	std::cout << "GotoOrigin: "<< position<<std::endl << angle << std::endl;
	TurnToAngle tto{2, robot, wheels, pass_orientation};
	tto.act();

	SetWheelSpeed mw{wheels, 1,1};
	mw.act();
}

GoToOrigin::GoToOrigin(RobotModel &robot, std::vector<WheelVREP *> &wheels, PassOrientation& pass_orientation_)
	: Action(1), robot(robot), wheels(wheels), origin(),pass_orientation(pass_orientation_)
{
}

