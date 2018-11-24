//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include <iostream>
#include <cmath>
#include "turn_angle.h"

void TurnAngle::act()
{

	double final_speed = max_speed;
	double calc_speed;

	double an = base_angle - angle;
	if(an >= M_PI)
		an = an - 2*M_PI;
	calc_speed = ((an) / (M_PI));

	if (calc_speed <= final_speed)
		final_speed = calc_speed;

	wheels[0]->setSpeed(base_speed-final_speed);
	wheels[1]->setSpeed(base_speed+final_speed);

}

TurnAngle::TurnAngle(RobotModel &robot, std::vector<WheelVREP *> &wheels)
				: robot(robot), wheels(wheels), angle(0), base_speed(0), Action(2), base_angle(0), max_speed(1.5)
{
}

void TurnAngle::setAngle(double angle)
{
	TurnAngle::angle = angle;
}

TurnAngle::TurnAngle(RobotModel &robot, std::vector<WheelVREP *> &wheels, double angle, double base_angle_)
				: Action{20}, robot(robot), wheels(wheels), angle(angle), base_angle(base_angle_), base_speed(0), max_speed(2)
{
}
