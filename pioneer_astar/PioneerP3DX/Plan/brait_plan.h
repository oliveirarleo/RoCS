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

class BraitPlan: public Planner
{
private:
	std::vector<PassSonarPosition *>& sonar_analyze_observers;
	bool running;
	Pipeline& pipeline;

	double no_detection_dist;
	double max_detection_dist;
	std::vector<double> detect;
	std::vector<double> braitenberg_l;
	std::vector<double> braitenberg_r;
	double v0;
	double v_left;
	double v_right;

public:
	BraitPlan(RobotModel &robot, std::vector<PassSonarPosition *>& sonar_analyze_observers, Pipeline& pipeline_);

	void run() override;
};


#endif // PIONEER_BRAIT_PLAN_H_
