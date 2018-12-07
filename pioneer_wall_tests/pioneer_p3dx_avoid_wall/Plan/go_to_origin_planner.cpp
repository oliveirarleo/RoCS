//
// Created by leleco on 06/12/18.
//

#include "go_to_origin_planner.h"
#include "../Execute/Actions/go_to_origin_action.h"

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
		std::shared_ptr <Action> go_to_origin(new GoToOriginAction("GoToOrigin", 1, *pipeline));
		pipeline->push(go_to_origin);
//		std::cout << position_analyze.getValue()[0] << "\n" << orientation_analyze.getValue()[0] << "\n";
	}

}
