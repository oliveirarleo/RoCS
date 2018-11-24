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
private:
	std::vector<RobotModel *> robot_models;
	std::vector<StrategyModel *> strategy_models;
	WorldModel *world_model;

public:
	Knowledge();

	const std::vector<RobotModel *> &getRobot_models() const;

	const std::vector<ReactiveModel *> &getReactive_models() const;

	const std::vector<StrategyModel *> &getStrategy_models() const;

	WorldModel *getWorld_model() const;
};

Knowledge::Knowledge()
	:robot_models(), strategy_models(), world_model(nullptr)
{
}

const std::vector<RobotModel *> &Knowledge::getRobot_models() const
{
	return robot_models;
}


const std::vector<StrategyModel *> &Knowledge::getStrategy_models() const
{
	return strategy_models;
}

WorldModel *Knowledge::getWorld_model() const
{
	return world_model;
}



#endif //KNOWLEDGE_H_


