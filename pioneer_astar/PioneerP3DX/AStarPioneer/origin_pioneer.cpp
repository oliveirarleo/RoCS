//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include <Analyze/analyze.h>
#include "origin_pioneer.h"
#include "../Knowledge/pioneer_p3dx_model.h"
#include "../Monitor/sonars_vrep_monitor.h"
#include "../Analyze/pass_sonar_position.h"
#include "../Plan/go_to_origin_planner.h"
#include "../Execute/execute_p3dx.h"
#include "../Knowledge/avoid_wall_model.h"

OriginPioneer::OriginPioneer()
{
	PioneerP3DXModel p3dx_model{};
	Connection connection = p3dx_model.getConnection();


	std::vector<SonarVREP *> sonars = p3dx_model.getSonars();

	SonarsVREPMonitor sonar_monitor{sonars};
	PassSonarPosition analyze{p3dx_model};
	sonar_monitor.attach(&analyze);

	std::vector<PassSonarPosition *> analyzes{};
	analyzes.push_back(&analyze);

	ExecuteP3DX execute{};

//	GoToOriginPlanner planner{p3dx_model, analyzes, execute.getPipeline()};
	AvoidWallModel awmReactiveModel{p3dx_model, execute.getPipeline()};

	sonar_monitor.startThread();
	analyze.startThread();

	std::this_thread::sleep_for(std::chrono::seconds(3));
	awmReactiveModel.startThread();
//	planner.startThread();
	execute.startThread();

	while (connection.isConnected())
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

}
