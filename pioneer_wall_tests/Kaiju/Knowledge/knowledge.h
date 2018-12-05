//
//
//

#ifndef KNOWLEDGE_H_
#define KNOWLEDGE_H_

#include <vector>
#include <Knowledge/robot_model.h>
#include <Knowledge/reactive_model.h>
#include <Knowledge/strategy_model.h>
#include <Knowledge/world_model.h>

class Knowledge
{
protected:
	std::vector<RobotModel *> robot_models;
//	std::vector<ReactiveModel *> reactive_models;
	std::vector<StrategyModel *> strategy_models;
	WorldModel *world_model;

public:
	Knowledge()
		:robot_models(), strategy_models(), world_model(nullptr)
	{
	}
};

#endif //KNOWLEDGE_H_
