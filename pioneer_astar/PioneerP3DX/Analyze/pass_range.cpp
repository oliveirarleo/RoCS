//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include <remoteApi/extApiPlatform.h>
#include "pass_range.h"

PassRange::PassRange(const RobotModel &robot) : Analyze(robot)
{
}

std::vector<RangeOutput> PassRange::process(std::vector<RangeOutput> ov)
{
	return ov;
}
