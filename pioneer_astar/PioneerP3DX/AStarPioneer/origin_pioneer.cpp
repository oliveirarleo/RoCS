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
#include "../Sensors/orientation_sensor.h"
#include "../Monitor/orientation_vrep_monitor.h"

OriginPioneer::OriginPioneer()
{
	PioneerP3DXModel p3dx_model{};
	Connection connection = p3dx_model.getConnection();


	std::vector<RangeVREP *> sonars = p3dx_model.getSonars();


	SonarsVREPMonitor sonar_monitor{sonars};
	PassSonarPosition sonar_position_analyze{p3dx_model};
	sonar_monitor.attach(&sonar_position_analyze);

	OrientationSensor* orientation_sensor = p3dx_model.getOrientationSensor();
	std::vector<OrientationSensor *> os;
	os.push_back(orientation_sensor);
	OrientationVREPMonitor orientation_monitor{os};
	PassOrientation pass_orientation{p3dx_model};
	orientation_monitor.attach(&pass_orientation);


	std::vector<PassSonarPosition *> analyzes{};
	analyzes.push_back(&sonar_position_analyze);

	ExecuteP3DX execute{};

	GoToOriginPlanner planner{p3dx_model, execute.getPipeline(), pass_orientation};
	AvoidWallModel awmReactiveModel{p3dx_model, execute.getPipeline()};

	sonar_monitor.startThread();
	sonar_position_analyze.startThread();

	orientation_monitor.startThread();
	pass_orientation.startThread();

	std::this_thread::sleep_for(std::chrono::seconds(3));
	awmReactiveModel.startThread();
	planner.startThread();
	execute.startThread();

	while (connection.isConnected())
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

}
