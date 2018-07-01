//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIONEER_ORIENTATION_SENSOR_H_
#define PIONEER_ORIENTATION_SENSOR_H_


#include <Sensors/sensor.h>
#include <Knowledge/robot_model.h>
#include "../Knowledge/euler_angle.h"
#include "../Connection/connection.h"

class OrientationSensor: public Sensor<EulerAngle>
{
public:
	RobotModel& robot;
	Connection& connection;
	int handle;


public:
	OrientationSensor(const std::string name_, RobotModel &robot);

	bool getData(EulerAngle &value) override;

};


#endif // PIONEER_ORIENTATION_SENSOR_H_