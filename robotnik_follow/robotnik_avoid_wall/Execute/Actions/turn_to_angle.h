//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
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
	WheelVREP *back_left_wheel;
	WheelVREP *back_right_wheel;
	Orientation &orientation;
	double desired_orientation;
	double base_speed;
	double turn_speed;

public:
	TurnToAngle(const std::string &name_, double value_, Pipeline *pipeline_, Orientation &orientation_, double desired_orientation_,
				double base_speed_, double turn_speed_);

private:
	void setActuators(std::vector<std::vector<Actuator *> > &actuators) override;

	void act() override;
};


#endif //PIONEER_TURN_TO_ANGLE_H
