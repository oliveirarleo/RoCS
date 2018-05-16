//
// Created by kaiju on 15/05/18.
//

#ifndef PIONEER_PIONEER_P_3_DX_MODEL_H
#define PIONEER_PIONEER_P_3_DX_MODEL_H

#include <Knowledge/robot_model.h>
#include <vector>
#include "../Connection/connection.h"
#include "Knowledge/position.h"
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
		std::vector< WheelVREP > wheels;

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

	const Position &getRobotPosition() const;

	const std::vector<SonarVREP> &getSonars() const;

	const std::vector<WheelVREP> &getWheels() const;


};


#endif //PIONEER_PIONEER_P_3_DX_MODEL_H
