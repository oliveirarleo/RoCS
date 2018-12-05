//
// Created by leleco on 05/12/18.
//

#include "pass_vrep_position.h"

PassVREPPosition::PassVREPPosition(Knowledge &knowledge_):Analyze(knowledge_)
{
}

std::vector<Position> PassVREPPosition::mergeAndProcess(std::vector<Position> ov)
{
	return ov;
}
