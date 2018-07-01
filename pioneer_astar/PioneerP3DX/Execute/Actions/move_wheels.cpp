//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include "move_wheels.h"

void MoveWheels::act()
{
	(wheels[0])->setSpeed(v_left);
	(wheels[1])->setSpeed(v_right);

}


MoveWheels::MoveWheels(std::vector<WheelVREP *> &wheels_, double v_left_, double v_right_) : Action(), wheels(wheels_),
																																														 v_left(v_left_),
																																														 v_right(v_right_)
{
}
