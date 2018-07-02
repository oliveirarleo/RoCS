//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include "turn_angle.h"

void TurnAngle::act()
{
	wheels[0]->setSpeed(base_speed*angle/3.14);
	wheels[1]->setSpeed(-base_speed*angle/3.14);
}

TurnAngle::TurnAngle(RobotModel &robot, std::vector<WheelVREP *> &wheels) : robot(robot), wheels(wheels), angle(0), base_speed(1), Action(2)
{
}

void TurnAngle::setAngle(double angle)
{
	TurnAngle::angle = angle;
}
