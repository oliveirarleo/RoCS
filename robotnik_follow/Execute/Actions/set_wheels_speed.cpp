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
//	std::string front_left_wheel_name = "joint_front_left_wheel";
//	std::string front_right_wheel_name = "joint_front_right_wheel";
//	std::string back_right_wheel_name = "joint_back_right_wheel";
//	std::string back_left_wheel_name = "joint_back_left_wheel";
	Action::actuators = actuators;
	left_wheel = (WheelVREP *) (actuators[0][0]);
	right_wheel = (WheelVREP *) (actuators[0][1]);
	back_left_wheel = (WheelVREP *) (actuators[0][3]);
	back_right_wheel = (WheelVREP *) (actuators[0][2]);

//    std::cout << actuators[0][0]->getName() << '\n';
//    std::cout << actuators[0][1]->getName() << '\n';
//    std::cout << actuators[0][2]->getName() << '\n';
//    std::cout << actuators[0][3]->getName() << '\n';
//	std::cout << actuators[0].size() << '\n';
}

void SetWheelsSpeed::act()
{
	if (left_wheel && right_wheel)
	{
//		std::cout << "Actuator go\n";
		(*left_wheel).setSpeed(left_wheel_speed);
		(*right_wheel).setSpeed(-right_wheel_speed);
		(*back_left_wheel).setSpeed(left_wheel_speed);
		(*back_right_wheel).setSpeed(-right_wheel_speed);
	}
	else
	{
		std::cout << "Actuator null\n";
	}

}