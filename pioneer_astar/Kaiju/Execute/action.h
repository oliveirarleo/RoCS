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

public:
	Action()
	{
	}

	virtual void act() = 0;
};

#endif //ARCH_ACTION_H_
