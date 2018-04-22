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
	bool is_connected = false;
	std::string robot_name = "Pioneer_p3dx";
	Position robot_position = Position{0, 0, 0};
	int robot_handle = -1;
	Connection connection{};

	std::vector< SonarVREP > range_sensors;
	std::vector< Actuator <double> > actuators;

	void verifyConnection();

	void getRobotPosition();

	void getRobotInfo();

	void instantiateSensors();

	void instantiateActuators();

public:
	Pioneer_p3dx();

	int getHandle();

};


#endif // ROCS_PIONEER_P_3_DX_H_

