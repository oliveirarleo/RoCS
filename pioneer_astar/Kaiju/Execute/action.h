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
private:
	std::vector<Action> actions;
	std::vector<Actuator> actuators;

	virtual std::vector<Action> decompose(Action action) = 0;

public:
	virtual void act();
};

#endif //ARCH_ACTION_H_
