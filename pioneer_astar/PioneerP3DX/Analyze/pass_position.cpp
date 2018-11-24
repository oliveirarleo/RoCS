//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include "pass_position.h"

PassPosition::PassPosition(const RobotModel &robot) : Analyze(robot)
{
}

std::vector<Position> PassPosition::process(std::vector<Position> ov)
{
	return ov;
}
