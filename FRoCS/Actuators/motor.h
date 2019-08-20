//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_MOTOR_H_
#define ARCH_MOTOR_H_

#include "Actuators/actuator.h"

class Motor : public Actuator
{
protected:
	double max_speed;

	Motor(std::string name_, double weight_, Position position_, double max_speed_):Actuator(name_, weight_, position_),
	                                                                                max_speed(max_speed_)
	{
	}

	Motor(std::string name_):Actuator(name_), max_speed(0)
	{
	}

	Motor():Actuator{}, max_speed{0}
	{
	}
};

#endif //ARCH_MOTOR_H_
