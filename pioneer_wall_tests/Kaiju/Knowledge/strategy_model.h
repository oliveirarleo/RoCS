//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_STRATEGY_MODEL_H_
#define ARCH_STRATEGY_MODEL_H_

#include <string>

class StrategyModel
{
	std::string name;

public:
	StrategyModel(std::string name):name(std::move(name))
	{
	}

};

#endif //ARCH_STRATEGY_MODEL_H_
