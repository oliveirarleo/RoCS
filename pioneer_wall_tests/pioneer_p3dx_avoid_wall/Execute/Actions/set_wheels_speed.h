//
// Created by leleco on 07/12/18.
//

#ifndef PIONEER_GO_AHEAD_H
#define PIONEER_GO_AHEAD_H


#include <Execute/action.h>
#include "../../Actuators/wheel_vrep.h"

class SetWheelsSpeed : public Action
{
private:
	WheelVREP* left_wheel;
	WheelVREP* right_wheel;

	double left_wheel_speed;
	double right_wheel_speed;

public:
	SetWheelsSpeed(const std::string &name_, double value_, Pipeline *pipeline_, double left_wheel_speed_, double right_wheel_speed_);

	void setActuators(std::vector<std::vector< Actuator* > > &actuators) override;

	void act() override;
};


#endif //PIONEER_GO_AHEAD_H
