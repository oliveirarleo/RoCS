//
// Created by leleco on 07/12/18.
//

#ifndef PIONEER_TURN_TO_ANGLE_H
#define PIONEER_TURN_TO_ANGLE_H


#include <Execute/action.h>
#include "../../Actuators/wheel_vrep.h"

class TurnToAngle : public Action
{
private:
	WheelVREP *left_wheel;
	WheelVREP *right_wheel;
	Orientation &orientation;
	double desired_orientation;
	bool clockwise;

public:
	TurnToAngle(const std::string &name_, double value_, Pipeline *pipeline_, Orientation &orientation_, double desired_orientation_, bool clockwise_);

private:
	void setActuators(std::vector<std::vector<Actuator *> > &actuators) override;

	void act() override;
};


#endif //PIONEER_TURN_TO_ANGLE_H
