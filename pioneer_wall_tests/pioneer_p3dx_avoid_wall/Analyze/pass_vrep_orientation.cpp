//
// Created by leleco on 05/12/18.
//

#include "pass_vrep_orientation.h"

PassVREPOrientation::PassVREPOrientation(Knowledge &knowledge_):Analyze(knowledge_)
{
}

std::vector<Orientation> PassVREPOrientation::mergeAndProcess(std::vector<Orientation> ov)
{
	return ov;
}
