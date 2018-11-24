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
#include <Util/position.h>

#include "../Connection/connection.h"
#include "../Sensors/range_vrep_sensor.h"
#include "../Actuators/wheel_vrep.h"
#include "../Sensors/orientation_vrep_sensor.h"
#include "../Sensors/position_vrep_sensor.h"

class PioneerP3DXModel : public RobotModel
{
private:
	int robot_handle;
	Connection connection;

	Position robot_position;
	Orientation robot_orientation;

//	SENSORS
	std::vector<RangeVREPSensor *> sonars;
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
	PioneerP3DXModel(Knowledge& knowledge_);

//		Get Methods

	int getHandle();

	std::string &getRobotName();

	int getRobotHandle();

	Connection &getConnection();

	Position &getRobotPosition();

	std::vector<RangeVREPSensor *> &getSonars();

	OrientationVREPSensor *getOrientationSensor();

	PositionVREPSensor *getPositionSensor();

	std::vector<WheelVREP *> &getWheels();

};

#endif // PIONEER_PIONEER_P_3_DX_MODEL_H_
