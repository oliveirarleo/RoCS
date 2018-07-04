//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include <Analyze/analyze.h>
#include <include/v_repConst.h>
#include "origin_pioneer.h"
#include "../Monitor/range_vrep_monitor.h"
#include "../Plan/go_to_origin_planner.h"
#include "../Execute/execute_p3dx.h"
#include "../Knowledge/ReactiveModels/avoid_wall_model.h"
#include "../Monitor/orientation_vrep_monitor.h"
#include "../Monitor/position_vrep_monitor.h"

OriginPioneer::OriginPioneer() : p3dx_model{}
{
//	Connecting
	Connection connection = p3dx_model.getConnection();


//	CONNECTING SENSORS, CREATING MONITORS AND ANALYZES
// Sonars
//	std::vector<RangeVREP *> sonars = p3dx_model.getSonars();
//	RangeVREPMonitor sonar_monitor{sonars};
//	PassRange sonar_position_analyze{p3dx_model};
//	sonar_monitor.attach(&sonar_position_analyze);

//	Orientation sensor
	std::vector<OrientationVREPSensor *> os;
	os.push_back(p3dx_model.getOrientationSensor());
	OrientationVREPMonitor orientation_monitor{os};
	PassOrientation pass_orientation{p3dx_model};
	orientation_monitor.attach(&pass_orientation);

//	Position sensor
	std::vector<PositionVREPSensor *> ps;
	ps.push_back(p3dx_model.getPositionSensor());
	PositionVREPMonitor position_monitor{ps};
	PassPosition pass_position{p3dx_model};
	position_monitor.attach(&pass_position);


// EXECUTE AND PLANNING CONNECTION, REACTION MODELS
	ExecuteP3DX execute{};

	GoToOriginPlanner planner{p3dx_model, execute.getPipeline(), pass_orientation, pass_position};

	AvoidWallModel awmReactiveModel{p3dx_model, execute.getPipeline()};


//	STARTING THREADS

//	SONAR
//	sonar_monitor.startThread();
//	sonar_position_analyze.startThread();

//	ORIENTATION
	orientation_monitor.startThread();
	pass_orientation.startThread();

//	POSITION
	position_monitor.startThread();
	pass_position.startThread();

//	REACTIVE MODEL, PLANNER AND EXECUTE
	awmReactiveModel.startThread();
	planner.startThread();
	execute.startThread();

	while (connection.isConnected())
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

}

OriginPioneer::~OriginPioneer()
{
	std::cout << "Stopping" << std::endl;
	simxStopSimulation(p3dx_model.getConnection().getClientId(), simx_opmode_oneshot);
	simxFinish(p3dx_model.getConnection().getClientId());
}
