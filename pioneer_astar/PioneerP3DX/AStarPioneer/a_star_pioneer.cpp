//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include <Analyze/analyze.h>
#include "a_star_pioneer.h"
#include "../Knowledge/pioneer_p3dx_model.h"
#include "../Monitor/sonars_vrep_monitor.h"
#include "../Analyze/pass_sonar_position.h"
#include "../Plan/brait_plan.h"
#include "../Execute/execute_p3dx.h"

AStarPioneer::AStarPioneer()
{
	PioneerP3DXModel p3dx_model{};

	std::vector<SonarVREP *> sonars = p3dx_model.getSonars();

	SonarsVREPMonitor sonar_monitor{sonars};
	PassSonarPosition analyze{p3dx_model};
	sonar_monitor.attach(&analyze);

	std::vector<PassSonarPosition *> analyzes{};
	analyzes.push_back(&analyze);

	ExecuteP3DX execute{};
	BraitPlan planner{p3dx_model, analyzes, execute.getPipeline()};

	sonar_monitor.startThread();
	analyze.startThread();

	std::this_thread::sleep_for(std::chrono::seconds(3));
	planner.startThread();
	execute.startThread();

	while (true)
	{
		std::this_thread::sleep_for(std::chrono::hours::max());
	}

}
