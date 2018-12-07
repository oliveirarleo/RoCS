//
// Created by leleco on 06/12/18.
//

#ifndef PIONEER_GO_TO_ORIGIN_ACTION_H
#define PIONEER_GO_TO_ORIGIN_ACTION_H


#include <Execute/action.h>
#include "../../Actuators/wheel_vrep.h"

class GoToOriginAction : public Action
{
private:
	WheelVREP* left_wheel;
	WheelVREP* right_wheel;

public:
	GoToOriginAction(const std::string &name_, double value_, Pipeline &pipeline_);

	void setActuators(std::vector<std::vector< Actuator* > > &actuators) override;

	void act() override;

};




#endif //PIONEER_GO_TO_ORIGIN_ACTION_H
