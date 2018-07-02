//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include <thread>
#include "move_wheels.h"

void MoveWheels::act()
{
	(wheels[0])->setSpeed(v_left);
	(wheels[1])->setSpeed(v_right);
	std::this_thread::sleep_for(std::chrono::milliseconds(50));
}


MoveWheels::MoveWheels(std::vector<WheelVREP *> &wheels_, double v_left_, double v_right_)
				: Action(2), wheels(wheels_), v_left(v_left_), v_right(v_right_)
{
}

MoveWheels::MoveWheels(std::vector<WheelVREP *> &wheels, double v_left, double v_right, double value_)
				: Action(value_), wheels(wheels), v_left(v_left), v_right(v_right)
{
}
