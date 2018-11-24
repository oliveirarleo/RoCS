//
// Created by leonardo on 04/10/18.
//

#ifndef PIONEER_KNOWLEDGE_H
#define PIONEER_KNOWLEDGE_H


#include <Knowledge/reactive_model.h>
#include <Knowledge/strategy_model.h>
#include <Knowledge/robot_model.h>
#include <Knowledge/world_model.h>

class Knowledge
{

private:
	std::vector<ReactiveModel*> reactive_models;
	std::vector<StrategyModel*> strategy_models;
	std::vector<RobotModel*> robot_models;
	WorldModel* world_model;

};


#endif //PIONEER_KNOWLEDGE_H


