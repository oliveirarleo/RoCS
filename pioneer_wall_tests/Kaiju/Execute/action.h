//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_ACTION_H_
#define ARCH_ACTION_H_

#include <vector>
#include <string>
#include <memory>
#include <ostream>
#include <Actuators/actuator.h>

class Pipeline;

class Action
{
protected:
	std::string name;
	double value;
	Pipeline *pipeline;
	std::vector< std::vector< Actuator*  > >	actuators;


public:
	Action(std::string name_, double value_, Pipeline *pipeline_):name(std::move(name_)), value(value_), pipeline(pipeline_), actuators()
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

	virtual void setActuators(std::vector< std::vector< Actuator* > > &actuators)
	{
		Action::actuators = actuators;
	}

	friend std::ostream &operator<<(std::ostream &os, const Action &action)
	{
		os << action.name << ", " << action.value;
		return os;
	}

	virtual void act() = 0;


};

#endif //ARCH_ACTION_H_
