//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_ACTION_H_
#define ARCH_ACTION_H_

#include<vector>
#include<string>
#include <ostream>
#include "../Actuators/actuator.h"

class Action
{
protected:
	double value;
	//std::string name;

public:
	Action(double value_): value(value_)
	{
	}

	double getValue() const
	{
		return value;
	}

	friend std::ostream &operator<<(std::ostream &os, const Action &action) {
		os << "value: " << action.value;
		return os;
	}

	virtual void act() = 0;


};

#endif //ARCH_ACTION_H_
