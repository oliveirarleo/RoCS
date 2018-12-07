//
// Created by leleco on 06/12/18.
//

#include "go_to_origin_action.h"

GoToOriginAction::GoToOriginAction(const std::string &name_, double value_, Pipeline &pipeline_)
	:Action(name_, value_, pipeline_), left_wheel(nullptr),right_wheel(nullptr)
{

}

void GoToOriginAction::setActuators(std::vector< std::vector< Actuator* > > &actuators)
{
	Action::actuators = actuators;
	left_wheel =(WheelVREP*)(actuators[0][0]);
	right_wheel = (WheelVREP*)(actuators[0][1]);
}

void GoToOriginAction::act()
{
	if(left_wheel && right_wheel)
	{
//		std::cout << "Actuator go\n";
		(*left_wheel).setSpeed(1);
		(*right_wheel).setSpeed(1);
	} else
	{
		std::cout << "Actuator null\n";
	}

}