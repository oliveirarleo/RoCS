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
	std::string name;
	double value;

public:
	Action(const std::string &name, double value) : name(name), value(value)
	{
	}

	const std::string &getName() const
	{
		return name;
	}

	double getValue() const
	{
		return value;
	}

	virtual void act() = 0;
};

#endif //ARCH_ACTION_H_
