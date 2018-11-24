//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIONEER_MOVE_WHEELS_H_
#define PIONEER_MOVE_WHEELS_H_


#include <Execute/action.h>
#include "../../Actuators/wheel_vrep.h"

class SetWheelSpeed : public Action
{
private:
	std::vector<WheelVREP *> &wheels;
	double v_left;
	double v_right;
	int wait;
public:
	void act() override;

	SetWheelSpeed(std::vector<WheelVREP *> &wheels, double v_left, double v_right);

	SetWheelSpeed(std::vector<WheelVREP *> &wheels, double v_left, double v_right, double value_);

	SetWheelSpeed(std::vector<WheelVREP *> &wheels, double v_left, double v_right,double value_, int wait);

};


#endif // PIONEER_MOVE_WHEELS_H_
