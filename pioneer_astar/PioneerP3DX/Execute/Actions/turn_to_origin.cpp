//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include "turn_to_origin.h"
#include "turn_angle.h"
#include "../../Analyze/pass_orientation.h"

#include <cmath>
#include <thread>
#include <iostream>

void TurnToOrigin::act()
{

	double an;
	EulerAngle angle;
	double epsilon = 0.05;
	double des_angle = (5.3);

	do{
		angle = pass_orientation.getValue()[0];
		an = des_angle - angle.getGama();
		if (an >= M_PI)
			an = an - 2 * M_PI;
		if (angle.isValid())
		{
			TurnAngle ta{robot, wheels, angle.getGama(), des_angle};
			ta.act();
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(20));
	}while (!((an) < epsilon && an > -epsilon));
}

TurnToOrigin::TurnToOrigin(double value_, RobotModel &robot, std::vector<WheelVREP *> &wheels, PassOrientation& pass_orientation_)
				: Action("TurnToOrigin", value_), robot(robot), wheels(wheels), pass_orientation(pass_orientation_)
{
}
