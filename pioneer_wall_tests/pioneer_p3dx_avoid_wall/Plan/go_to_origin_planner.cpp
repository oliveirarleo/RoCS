//
// Created by leleco on 06/12/18.
//

#include "go_to_origin_planner.h"

GoToOriginPlanner::GoToOriginPlanner(Knowledge &knowledge, PassVREPPosition &position_analyze, PassVREPOrientation &orientation_analyze)
	:Planner(knowledge), position_analyze(position_analyze), orientation_analyze(orientation_analyze)
{
}

GoToOriginPlanner::GoToOriginPlanner(Knowledge &knowledge, Pipeline *pipeline, PassVREPPosition &position_analyze_,
                                     PassVREPOrientation &orientation_analyze_)
	:Planner(knowledge, pipeline), position_analyze(position_analyze_), orientation_analyze(orientation_analyze_)
{
}

void GoToOriginPlanner::planIteration()
{
	if (pipeline && pipeline->isEmpty())
	{
//		std::cout << position_analyze.getValue()[0] << "\n" << orientation_analyze.getValue()[0] << "\n";
	}

}
