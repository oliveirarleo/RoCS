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

#include "../Connection/connection.h"
#include "../Sensors/sonar_vrep.h"
#include "../Actuators/wheel_vrep.h"

class PioneerP3DXModel : public RobotModel
{
private:
	std::string robot_name;
	int robot_handle;
	Connection connection;
	Position robot_position;
	std::vector<SonarVREP> sonars;
//		std::vector< ForceSensorVREP > force_sensors;
	std::vector<WheelVREP> wheels;

public:
	PioneerP3DXModel();

	void verifyConnection();

	void connectToSonars();

	void connectToWheels();

	void connectToRobot();

//		Get Methods

	int getHandle();

	const std::string &getRobotName() const;

	int getRobotHandle() const;

	const Connection &getConnection() const;

	const Position &getRobotPosition();

	const std::vector<SonarVREP> &getSonars() const;

	const std::vector<WheelVREP> &getWheels() const;

};

#endif // PIONEER_PIONEER_P_3_DX_MODEL_H_
