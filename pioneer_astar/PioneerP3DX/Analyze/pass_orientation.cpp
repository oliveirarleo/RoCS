//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include "pass_orientation.h"

PassOrientation::PassOrientation(const RobotModel &robot) : Analyze(robot)
{
}

std::vector<EulerAngle> PassOrientation::mergeAndProcess(std::vector<EulerAngle> ov)
{
	return ov;
}
