//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIONEER_BRAIT_PLAN_H_
#define PIONEER_BRAIT_PLAN_H_

#include <Plan/planner.h>
#include <Knowledge/position.h>
#include <Util/pipeline.h>
#include "../Analyze/pass_sonar_position.h"

class GoToOriginPlanner: public Planner
{
private:
	std::vector<PassSonarPosition *>& sonar_analyze_observers;


public:
	GoToOriginPlanner(RobotModel &robot, Pipeline& pipeline_, std::vector<PassSonarPosition*> sonar_analyze_observers_);

	void run() override;
};


#endif // PIONEER_BRAIT_PLAN_H_
