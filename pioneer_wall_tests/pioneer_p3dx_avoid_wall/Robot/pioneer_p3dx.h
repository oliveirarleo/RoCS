//
// Created by leonardo on 16/11/18.
//

#ifndef PIONEER_PIONEER_P3DX_H
#define PIONEER_PIONEER_P3DX_H


#include <Robot/robot.h>
#include "../Knowledge/p3dx_knowledge.h"
#include "../Knowledge/avoid_wall_model.h"
#include "../Sensors/orientation_vrep_sensor.h"
#include "../Sensors/position_vrep_sensor.h"
#include "../Monitor/range_vrep_monitor.h"
#include "../Monitor/position_vrep_monitor.h"
#include "../Monitor/orientation_vrep_monitor.h"
#include "../Analyze/pass_vrep_range.h"
#include "../Analyze/pass_vrep_position.h"
#include "../Analyze/pass_vrep_orientation.h"
#include "../Plan/go_to_origin_planner.h"


class PioneerP3DX : public Robot
{
private:
	P3DXKnowledge knowledge;

	Connection &connection;

	//	SENSORS
	std::vector<RangeVREPSensor> range_sensors;
	OrientationVREPSensor orientation_sensor;
	PositionVREPSensor position_sensor;
//		std::vector< ForceSensorVREP > force_sensors;

	//	ACTUATORS
	std::vector<WheelVREP> wheels;
	std::vector<Actuator*> wheel_ptrs;



	//	MONITORS
	RangeVREPMonitor range_monitor;
	PositionVREPMonitor position_monitor;
	OrientationVREPMonitor orientation_monitor;

	//	ANALYZES
	PassVREPRange range_analyze;
	PassVREPPosition position_analyze;
	PassVREPOrientation orientation_analyze;

	//  PLANNER
	GoToOriginPlanner planner;

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

	void connectToWheels();


public:
	PioneerP3DX();

	void run();

};


#endif //PIONEER_PIONEER_P_3_DX_H
