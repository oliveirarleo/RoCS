//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIONEER_PIONEER_P_3_DX_MODEL_H_
#define PIONEER_PIONEER_P_3_DX_MODEL_H_

#include <string>
#include <vector>

#include <Knowledge/robot_model.h>
#include <Knowledge/position.h>
#include <Execute/action.h>

#include "../../Connection/connection.h"
#include "../../Sensors/range_vrep.h"
#include "../../Actuators/wheel_vrep.h"
#include "../../Sensors/orientation_vrep_sensor.h"
#include "../../Sensors/position_vrep_sensor.h"

class PioneerP3DXModel : public RobotModel
{
private:
	std::string robot_name;
	int robot_handle;
	Connection connection;

	Position robot_position;
	EulerAngle robot_orientation;
	Action* current_action;


private:

//	SENSORS
	std::vector<RangeVREP *> sonars;
	OrientationVREPSensor *orientation_sensor;
	PositionVREPSensor *position_sensor;
//		std::vector< ForceSensorVREP > force_sensors;

//	ACTUATORS
	std::vector<WheelVREP *> wheels;

private:

	void verifyConnection();

	void connectToSonars();

	void connectToOrientationSensor();

	void connectToPositionSensor();

	void connectToWheels();

	void connectToRobot();

public:
	PioneerP3DXModel();

//		Get Methods

	int getHandle();

	std::string &getRobotName();

	int getRobotHandle();

	Connection &getConnection();

	Position getRobotPosition();

	EulerAngle getRobotOrientation();

	std::vector<RangeVREP *> &getSonars();

	OrientationVREPSensor *getOrientationSensor();

	PositionVREPSensor *getPositionSensor();

	std::vector<WheelVREP *> &getWheels();

	void setCurrentAction(Action *current_action);

	Action *getCurrentAction() const;

};

#endif // PIONEER_PIONEER_P_3_DX_MODEL_H_
