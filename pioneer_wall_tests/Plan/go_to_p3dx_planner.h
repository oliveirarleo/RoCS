//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIONEER_GO_TO_ORIGIN_PLANNER_H
#define PIONEER_GO_TO_ORIGIN_PLANNER_H


#include <Plan/planner.h>
#include "../Analyze/pass_vrep_position.h"
#include "../Analyze/pass_vrep_orientation.h"

class GoToOriginPlanner : public Planner
{
private:
	PassVREPPosition &position_analyze;
	PassVREPOrientation &orientation_analyze;
	int state;
	Position destination;

public:
	GoToOriginPlanner(Knowledge &knowledge, PassVREPPosition &position_analyze, PassVREPOrientation &orientation_analyze);

	GoToOriginPlanner(Knowledge &knowledge, Pipeline *pipeline, PassVREPPosition &position_analyze_,
	                  PassVREPOrientation &orientation_analyze_);

	void planIteration() override;

};


#endif //PIONEER_GO_TO_ORIGIN_PLANNER_H
