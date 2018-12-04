//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIONEER_POSITION_SENSOR_H_
#define PIONEER_POSITION_SENSOR_H_


#include <Util/position.h>
#include <Sensors/sensor.h>
#include <Knowledge/robot_model.h>
#include "../Connection/connection.h"
#include "../Knowledge/pioneer_p3dx_model.h"

class PositionVREPSensor : public Sensor<Position>
{
private:
	Connection &connection;
	int handle;

public:
	PositionVREPSensor(std::string name_, Connection& connection_, PioneerP3DXModel& robot_model_);

	bool getData(Position &value) override;

};

#endif // PIONEER_POSITION_SENSOR_H_
