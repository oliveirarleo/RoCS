//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_BLACKBOARD_H_
#define ARCH_BLACKBOARD_H_

#include "reactive_model.h"
#include "robot_model.h"
#include "strategy_model.h"
#include "world_model.h"

class Blackboard
{
private:
	WorldModel world_model;
	StrategyModel strategy_model;
	RobotModel robot_model;
	ReactiveModel reactive_model;

	Blackboard blackboard;
};

#endif //ARCH_BLACKBOARD_H_
