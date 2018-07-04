//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include <thread>
#include "set_wheel_speed.h"

void SetWheelSpeed::act()
{
	(wheels[0])->setSpeed(v_left);
	(wheels[1])->setSpeed(v_right);
	std::this_thread::sleep_for(std::chrono::milliseconds(wait));
}


SetWheelSpeed::SetWheelSpeed(std::vector<WheelVREP *> &wheels_, double v_left_, double v_right_)
				: Action(2), wheels(wheels_), v_left(v_left_), v_right(v_right_),wait(50)
{
}

SetWheelSpeed::SetWheelSpeed(std::vector<WheelVREP *> &wheels, double v_left, double v_right, double value_)
				: Action(value_), wheels(wheels), v_left(v_left), v_right(v_right),wait(50)
{
}

SetWheelSpeed::SetWheelSpeed(std::vector<WheelVREP *> &wheels, double v_left, double v_right,double value_, int wait)
				: Action(value_), wheels(wheels), v_left(v_left), v_right(v_right), wait(wait)
{
}
