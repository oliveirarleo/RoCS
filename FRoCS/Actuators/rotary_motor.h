//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_ROTARY_MOTOR_H_
#define ARCH_ROTARY_MOTOR_H_

#include "motor.h"

class RotaryMotor : public Motor
{
public:
	RotaryMotor(std::string name_, double weight_, Position position_, double max_speed_):Motor(name_, weight_,
	                                                                                            position_, max_speed_)
	{
	}

	RotaryMotor(std::string name_):Motor(name_)
	{
	}

	RotaryMotor():Motor()
	{
	}

};

#endif //ARCH_ROTARY_MOTOR_H_
