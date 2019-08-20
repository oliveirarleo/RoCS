//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIONEER_ROBOT_H
#define PIONEER_ROBOT_H


#include <Execute/execute.h>
#include <Plan/planner.h>
#include <Monitor/monitor.h>
#include <Analyze/analyze.h>

class Robot
{
protected:
	std::string name;
	Knowledge knowledge;

	Execute execute;

	std::vector<std::vector<Actuator *> > actuators;

public:
	explicit Robot(std::string name_)
		:name(std::move(name_)), knowledge(), execute(knowledge), actuators()
	{
	}
};


#endif //PIONEER_ROBOT_H
