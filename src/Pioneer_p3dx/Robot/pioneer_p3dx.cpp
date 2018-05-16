//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include "pioneer_p3dx.h"

#include <iostream>

extern "C"
{
#include "extApi.h"
#include "v_repConst.h"
}

#include "../Connection/connection.h"
#include "../Monitor/monitor_sonar_vrep.h"
#include "../Analyze/analyze_pioneer_p_3_dx.h"
#include "../Plan/planner_pioneer_p3dx.h"
#include "../Knowledge/pioneer_p3dx_model.h"

PioneerP3DX::PioneerP3DX()
{

	PioneerP3DXModel p3dx_model{};

	//	Connect to server via ip and
	p3dx_model.verifyConnection();
	p3dx_model.connectToRobot();

	Connection connection = p3dx_model.getConnection();

	std::vector< SonarVREP > sonars = p3dx_model.getSonars();
	std::vector<MonitorSonarVrep> sonars_monitors;
	std::vector<Observer *> sonar_observers;
	for (int num_sonars = 0; num_sonars < 16; ++num_sonars)
	{
		MonitorSonarVrep sonar_monitor{sonars[num_sonars], sonar_observers};
		sonars_monitors.push_back(sonar_monitor);
	}

	{
		std::cout << (sonars[0]);
	}



	AnalyzePioneerP3DX analyze{sonars_monitors};
	std::vector< AnalyzePioneerP3DX > analyzes;
	analyzes.push_back(analyze);

	PlannerPioneerP3DX planner{p3dx_model, analyzes};
	planner.runPlanner();

}


//void PioneerP3DX::getRobotPosition()
//{
//	float pos[3];
//	simxGetObjectPosition(connection.getClientId(), robot_handle, -1, pos, simx_opmode_streaming);
//	robot_position.setPosition((double) pos[0], (double) pos[1], (double) pos[2]);
//}
