//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIONEER_WHEEL_VREP_H_
#define PIONEER_WHEEL_VREP_H_

#include <Actuators/rotary_motor.h>
#include <Knowledge/knowledge.h>
#include "../Connection/connection.h"

class WheelVREP : public RotaryMotor
{
private:
	int handle;
	Knowledge &knowledge;
	Connection &connection;
public:
	WheelVREP(std::string name_, Knowledge &knowledge);

	void setSpeed(double speed);

};


#endif // PIONEER_WHEEL_VREP_H_
