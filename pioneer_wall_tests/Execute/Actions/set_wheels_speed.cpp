//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include "set_wheels_speed.h"

SetWheelsSpeed::SetWheelsSpeed(const std::string &name_, double value_, Pipeline *pipeline_, double left_wheel_speed_,
                               double right_wheel_speed_)
	:Action(name_, value_, pipeline_), left_wheel(nullptr), right_wheel(nullptr), left_wheel_speed(left_wheel_speed_),
	 right_wheel_speed(right_wheel_speed_)
{

}

void SetWheelsSpeed::setActuators(std::vector<std::vector<Actuator *> > &actuators)
{
	Action::actuators = actuators;
	left_wheel = (WheelVREP *) (actuators[0][0]);
	right_wheel = (WheelVREP *) (actuators[0][1]);
}

void SetWheelsSpeed::act()
{
	if (left_wheel && right_wheel)
	{
//		std::cout << "Actuator go\n";
		(*left_wheel).setSpeed(left_wheel_speed);
		(*right_wheel).setSpeed(right_wheel_speed);
	}
	else
	{
		std::cout << "Actuator null\n";
	}

}