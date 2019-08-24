//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include "pass_vrep_position.h"

PassVREPPosition::PassVREPPosition(Knowledge &knowledge_):Analyze(knowledge_)
{
}

std::vector<Position> PassVREPPosition::mergeAndProcess(std::vector<Position> ov)
{
	return ov;
}
