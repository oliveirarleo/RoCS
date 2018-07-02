//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_ACTION_H_
#define ARCH_ACTION_H_

#include <vector>
#include "../Actuators/actuator.h"

class Action
{
protected:
	double value;
public:
	Action(double value_): value(value_)
	{
	}

	double getValue() const
	{
		return value;
	}

	virtual void act() = 0;
};

#endif //ARCH_ACTION_H_
