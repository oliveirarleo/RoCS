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
#include "../Analyze/pass_range.h"
#include "../Analyze/pass_orientation.h"
#include "../Analyze/pass_position.h"
#include "../Actuators/wheel_vrep.h"

class GoToOriginPlanner : public Planner
{
private:
	PassOrientation &pass_orientation;
	PassPosition &pass_position;

	std::vector< WheelVREP * > wheels;


public:
	GoToOriginPlanner(RobotModel &robot, Pipeline &pipeline_, PassOrientation &pass_orientation_, PassPosition &pass_position_);

	void run() override;
};


#endif // PIONEER_BRAIT_PLAN_H_
