//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include <Analyze/analyze.h>
#include "a_star_pioneer.h"
#include "../Knowledge/pioneer_p3dx_model.h"
#include "../Monitor/sonar_vrep_monitor.h"
#include "../Analyze/pass_sonar_position.h"
#include "../Plan/brait_plan.h"
#include "../Execute/execute_p3dx.h"

AStarPioneer::AStarPioneer()
{
	PioneerP3DXModel p3dx_model{};

	std::vector<SonarVREP *> sonars = p3dx_model.getSonars();
	std::vector<SonarVREPMonitor *> sonar_monitors;
	std::vector<PassSonarPosition *> analyzes;

	for (int i = 0; i < 16; ++i)
	{
//		std::cout << i << std::endl;
		sonar_monitors.push_back(new SonarVREPMonitor{*sonars[i]});
		analyzes.push_back(new PassSonarPosition{p3dx_model});
		sonar_monitors[i]->attach(analyzes[i]);
	}
	ExecuteP3DX execute{};
	BraitPlan planner{p3dx_model, analyzes, execute.getPipeline()};


	for (int i = 0; i < 16; ++i)
	{
		sonar_monitors[i]->startThread();
		analyzes[i]->startThread();
	}
//
	planner.startThread();
	execute.startThread();

	while (true)
	{
		std::this_thread::sleep_for(std::chrono::hours::max());
	}

}
