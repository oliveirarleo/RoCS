//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIONEER_PIONEER_P3DX_H
#define PIONEER_PIONEER_P3DX_H


#include <Robot/robot.h>
#include <P3DXPositionSensor.h>
#include <P3DXPositionMonitor.h>
#include <PassP3DXPosition.h>
#include "robotnik_knowledge.h"
#include "../Actuators/wheel_vrep.h"
#include "../Sensors/orientation_vrep_sensor.h"
#include "../Sensors/position_vrep_sensor.h"
#include "../Monitor/range_vrep_monitor.h"
#include "../Monitor/position_vrep_monitor.h"
#include "../Monitor/orientation_vrep_monitor.h"
#include "../Analyze/pass_vrep_range.h"
#include "../Analyze/pass_vrep_position.h"
#include "../Analyze/pass_vrep_orientation.h"
#include "../Plan/go_to_origin_planner.h"


class Robotnik : public Robot
{
private:
	RobotnikKnowledge knowledge;

	Connection &connection;

	//	SENSORS
	std::vector<RangeVREPSensor> range_sensors;
	OrientationVREPSensor orientation_sensor;
	PositionVREPSensor position_sensor;
	P3DXPositionSensor p3dx_position_sensor;
//		std::vector< ForceSensorVREP > force_sensors;

	//	ACTUATORS
	std::vector<WheelVREP> wheels;
	std::vector<Actuator *> wheel_ptrs;


	//	MONITORS
	RangeVREPMonitor range_monitor;
	PositionVREPMonitor position_monitor;
	OrientationVREPMonitor orientation_monitor;
	P3DXPositionMonitor p3dx_position_monitor;

	//	ANALYZES
	PassVREPRange range_analyze;
	PassVREPPosition position_analyze;
	PassVREPOrientation orientation_analyze;
	PassP3DXPosition p3dx_position_analyze;

	//  PLANNER
	GoToP3DXPlanner planner;

	std::chrono::seconds lifetime;


private:

	void verifyConnection();

	void setSensors();

	void setActuators();

	void setMonitors();

	void setAnalyzes();

	void setPlan();

	void setExecute();

	void setReactiveModels();

	void connectToSonars();

	void connectToOrientationSensor();

	void connectToPositionSensor();

	void connectToP3DXPositionSensor();

	void connectToWheels();


public:
	Robotnik();

	void run();

};


#endif //PIONEER_PIONEER_P_3_DX_H
