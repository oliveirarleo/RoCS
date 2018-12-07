//
// Created by leonardo on 16/11/18.
//

#include "pioneer_p3dx.h"
#include "../Knowledge/p3dx_knowledge.h"
#include "../Knowledge/avoid_wall_model.h"

extern "C"
{
#include <include/v_repConst.h>
}

PioneerP3DX::PioneerP3DX()
	:Robot("Pioneer_p3dx"), connection(knowledge.getConnection()), range_sensors(),
	 orientation_sensor(connection), position_sensor(connection), wheels(), wheel_ptrs(), range_monitor(knowledge),
	 position_monitor(knowledge), orientation_monitor(knowledge), range_analyze(knowledge), position_analyze(knowledge),
	 orientation_analyze(knowledge), planner(knowledge, position_analyze, orientation_analyze)
{
	verifyConnection();

	int robot_handle = -1;
	if (simxGetObjectHandle(connection.getClientId(), (const simxChar *) name.c_str(), (simxInt *) &robot_handle,
	                        (simxInt) simx_opmode_oneshot_wait) == simx_return_ok)
	{
		std::cout << "Connected to robot: " << name << " handle: " << robot_handle << std::endl;
		connection.setRobotHandle(robot_handle);
		setSensors();
		setActuators();

		setMonitors();
		setAnalyzes();
		setPlan();
		setExecute();
		setReactiveModels();
	}
	else
	{
		std::cout << "Could not connect to robot: " << name << std::endl;
		exit(1);
	}
}


void PioneerP3DX::run()
{
	std::cout << "rodando\n";
	range_monitor.startThread();
	position_monitor.startThread();
	orientation_monitor.startThread();

	range_analyze.startThread();
	position_analyze.startThread();
	orientation_analyze.startThread();

	execute.startThread();

	knowledge.getAvoidWallModel().startThread();

	planner.startThread();

	std::this_thread::sleep_for(std::chrono::seconds(150));

}

void PioneerP3DX::verifyConnection()
{
	if (connection.isConnected())
	{
		std::cout << "Connected to client: " << connection.getClientId() << std::endl;
	}
	else
	{
		std::cout << "Could not connect to client" << std::endl;
		exit(1);
	}
}


void PioneerP3DX::connectToSonars()
{

	for (int num_sonars = 1; num_sonars <= 16; ++num_sonars)
	{
		std::string sonar_name = "Pioneer_p3dx_ultrasonicSensor" + std::to_string(num_sonars);
		range_sensors.emplace_back(sonar_name, connection);
	}
}

void PioneerP3DX::connectToOrientationSensor()
{
	orientation_sensor.connect(connection.getRobotHandle());
	Orientation robot_orientation;
	orientation_sensor.getData(robot_orientation);
	std::cout << "First Ori: " << robot_orientation << std::endl;
}

void PioneerP3DX::connectToPositionSensor()
{
	position_sensor.connect(connection.getRobotHandle());
	Position robot_position;
	position_sensor.getData(robot_position);
	std::cout << "First Pos: " << robot_position << std::endl;
}

void PioneerP3DX::connectToWheels()
{
	std::string left_wheel_name = "Pioneer_p3dx_leftMotor";
	wheels.emplace_back(left_wheel_name, connection);


	std::string right_wheel_name = "Pioneer_p3dx_rightMotor";
	wheels.emplace_back(right_wheel_name, connection);
}

void PioneerP3DX::setSensors()
{
	connectToSonars();
	connectToOrientationSensor();
	connectToPositionSensor();
}


void PioneerP3DX::setActuators()
{
	connectToWheels();
	wheel_ptrs.push_back(&wheels[0]);
	wheel_ptrs.push_back(&wheels[1]);
	actuators.push_back(wheel_ptrs);

}

void PioneerP3DX::setMonitors()
{
	for(RangeVREPSensor &s : range_sensors)
	{
		range_monitor.insertSensor(&s);
	}
	position_monitor.insertSensor(&position_sensor);
	orientation_monitor.insertSensor(&orientation_sensor);
}

void PioneerP3DX::setAnalyzes()
{
	range_monitor.attach(&range_analyze);
	position_monitor.attach(&position_analyze);
	orientation_monitor.attach(&orientation_analyze);

}

void PioneerP3DX::setPlan()
{
	planner.setPipeline(&execute.getPipeline());
}

void PioneerP3DX::setExecute()
{
	execute.setActuators(actuators);
}

void PioneerP3DX::setReactiveModels()
{
	knowledge.getAvoidWallModel().setPipeline(&execute.getPipeline());
}
