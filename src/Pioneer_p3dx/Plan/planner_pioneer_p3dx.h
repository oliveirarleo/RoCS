//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIONEER_PLANNER_H_
#define PIONEER_PLANNER_H_

#include "Plan/planner.h"
#include "Analyze/analyze.h"
//#include "Execute/execute.h"
#include "Robot/robot.h"
#include "../Connection/connection.h"

class PlannerPioneerP3DX : public Planner
{
private:
	RobotModel &robot;
	std::vector< AnalyzePioneerP3DX > analyzes;
//	Execute execute;
	double no_detection_dist;
	double max_detection_dist;
	std::vector<double> detect;
	std::vector<double> braitenberg_l;
	std::vector<double> braitenberg_r;
	double v0;
	double v_left;
	double v_right;


public:
	PlannerPioneerP3DX(RobotModel &robot_, std::vector<AnalyzePioneerP3DX> &analyzes_);
	void runPlanner();
};


#endif // PIONEER_PLANNER_H_
