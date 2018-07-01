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
	std::vector<SonarVREP *> sonars;
//		std::vector< ForceSensorVREP > force_sensors;
	std::vector<WheelVREP *> wheels;

private:

	void verifyConnection();

	void connectToSonars();

	void connectToWheels();

	void connectToRobot();



public:
	PioneerP3DXModel();

//		Get Methods

	int getHandle();

	std::string &getRobotName();

	int getRobotHandle();

	Connection &getConnection();

	Position &getRobotPosition();

	std::vector<SonarVREP *> &getSonars();

	std::vector<WheelVREP *> &getWheels();

};

#endif // PIONEER_PIONEER_P_3_DX_MODEL_H_
