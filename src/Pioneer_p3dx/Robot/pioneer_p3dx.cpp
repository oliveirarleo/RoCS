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

Pioneer_p3dx::Pioneer_p3dx() : is_connected{false},
															 robot_name{"Pioneer_p3dx"},
															 robot_position{0, 0, 0},
															 robot_handle{-1},
															 connection{}
{
	//	Connect to server via ip and
	verifyConnection();
	getRobotInfo();

	std::vector<MonitorSonarVrep> sonars;
	for (int num_sonars = 1; num_sonars <= 16; ++num_sonars)
	{
		std::string sonar_name = "Pioneer_p3dx_ultrasonicSensor" + std::to_string(num_sonars);
		SonarVREP sonar{sonar_name, connection, *this};
		std::vector<Observer *> observers;
		MonitorSonarVrep sonar_monitor{sonar, observers};
		sonars.push_back(sonar_monitor);

	}

	{
		std::cout << (sonars[0]);
	}


	AnalyzePioneerP3DX analyze{sonars};
	std::vector< AnalyzePioneerP3DX > analyzes;
	analyzes.push_back(analyze);

	PlannerPioneerP3DX planner{*this, connection, analyzes};
	planner.runPlanner();

}

void Pioneer_p3dx::verifyConnection()
{
	using namespace std;

	if (connection.isConnected())
	{
		cout << "Connected to client: " << connection.getClientId() << endl;
	}
	else
	{
		cout << "Not connected to client" << endl;
		exit(1);
	}
}

void Pioneer_p3dx::getRobotPosition()
{
	float pos[3];
	simxGetObjectPosition(connection.getClientId(), robot_handle, -1, pos, simx_opmode_streaming);
	robot_position.setPosition((double) pos[0], (double) pos[1], (double) pos[2]);
}

void Pioneer_p3dx::getRobotInfo()
{
	if (simxGetObjectHandle(connection.getClientId(), (const simxChar *) robot_name.c_str(), (simxInt *) &robot_handle,
													(simxInt) simx_opmode_oneshot_wait) == simx_return_ok)
	{
		is_connected = true;
		std::cout << "Connected to robot: " << robot_name << std::endl;

		getRobotPosition();
	}
	else
	{
		std::cout << "Not connected to robot: " << robot_name << std::endl;
	}
}

int Pioneer_p3dx::getHandle()
{
	return robot_handle;
}

const std::string &Pioneer_p3dx::getRobotName() const
{
	return robot_name;
}

const Position &Pioneer_p3dx::getRobotPosition() const
{
	return robot_position;
}

int Pioneer_p3dx::getRobotHandle() const
{
	return robot_handle;
}

const Connection &Pioneer_p3dx::getConnection() const
{
	return connection;
}
