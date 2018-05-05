//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ROCS_PIONEER_P_3_DX_H_
#define ROCS_PIONEER_P_3_DX_H_

#include "Robot/robot.h"
#include "Sensors/sensor.h"
#include "Actuators/actuator.h"
#include "../Connection/connection.h"
#include "../Sensors/sonar_vrep.h"
#include <vector>

class Pioneer_p3dx : public Robot
{
private:
	bool is_connected;
	std::string robot_name;
	Position robot_position;
	int robot_handle;
	Connection connection;

	void verifyConnection();

	void getRobotPosition();

	void getRobotInfo();

public:
	Pioneer_p3dx();


	int getHandle();

	const std::string &getRobotName() const;

	const Position &getRobotPosition() const;

	int getRobotHandle() const;

	const Connection &getConnection() const;

};


#endif // ROCS_PIONEER_P_3_DX_H_

