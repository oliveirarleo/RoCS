//
// Created by leleco on 24/11/18.
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
	Knowledge knowledge;
	std::vector<ReactiveModel *> reactive_models;

	Planner *planner;
	Execute execute;

public:
	Robot()
		:knowledge(), reactive_models(), planner(nullptr), execute(knowledge)
	{
	}
};


#endif //PIONEER_ROBOT_H
