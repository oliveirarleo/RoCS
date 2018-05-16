//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_ACTUATOR_H_
#define ARCH_ACTUATOR_H_

#include "actuator_accessor.h"
#include "../Knowledge/position.h"

class Actuator : public ActuatorAccessor
{
protected:
	std::string name;
	double weight;
	Position position;

public:
	Actuator(std::string name_, double weight_, Position position_) : name{name_}, weight(weight_), position(position_)
	{
	}

	Actuator(std::string name_) : name(name_), weight{0}, position{}
	{
	}

	Actuator() : name{}, weight{0}, position{}
	{
	}
};

#endif //ARCH_ACTUATOR_H_
