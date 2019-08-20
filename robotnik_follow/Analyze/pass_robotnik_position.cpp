//
// Created by leleco on 06/07/19.
//

#include <Knowledge/knowledge.h>
#include "pass_robotnik_position.h"


PassRobotnikPosition::PassRobotnikPosition(Knowledge &knowledge_):Analyze(knowledge_)
{
}

std::vector<Position> PassRobotnikPosition::mergeAndProcess(std::vector<Position> ov)
{
    return ov;
}
