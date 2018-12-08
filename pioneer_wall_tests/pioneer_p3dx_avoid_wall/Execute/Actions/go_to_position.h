//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIONEER_GO_TO_ORIGIN_ACTION_H
#define PIONEER_GO_TO_ORIGIN_ACTION_H


#include <Execute/action.h>
#include "../../Actuators/wheel_vrep.h"

class GoToPosition : public Action
{
private:
	WheelVREP *left_wheel;
	WheelVREP *right_wheel;
	Position position;
	Orientation orientation;
	Position origin;
	double angle_threshold;
	double distance_threshold;

public:
	GoToPosition(const std::string &name_, double value_, Pipeline *pipeline_, Position position_, Orientation orientation_, Position destination);

	void setActuators(std::vector<std::vector<Actuator *> > &actuators) override;

	void act() override;

};


#endif //PIONEER_GO_TO_ORIGIN_ACTION_H
