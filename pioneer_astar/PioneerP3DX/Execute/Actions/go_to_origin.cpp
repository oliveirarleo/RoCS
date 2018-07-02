//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include <iostream>
#include "go_to_origin.h"

void GoToOrigin::act()
{
	std::cout << "GotoOrigin: "<< position << angle << std::endl;

}

GoToOrigin::GoToOrigin(RobotModel &robot, std::vector<WheelVREP *> &wheels, const Position &position, const EulerAngle &angle)
				: robot(robot), wheels(wheels), position(position), angle(angle), origin(), Action(1)
{
}

