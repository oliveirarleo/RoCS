//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include "go_to_p3dx_planner.h"
#include "../Execute/Actions/go_to_position.h"

GoToP3DXPlanner::GoToP3DXPlanner(Knowledge &knowledge, PassVREPPosition &position_analyze,
		PassVREPOrientation &orientation_analyze, PassRobotnikPosition &p3dx_positon_analyze_)
	:Planner(knowledge), position_analyze(position_analyze), orientation_analyze(orientation_analyze),
	p3dx_positon_analyze(p3dx_positon_analyze_), state(1),
	 destination(2, 2, 0.1387)
{
}

void GoToP3DXPlanner::planIteration()
{

//	std::cout << position_analyze.getValue()[0] << "," << pipeline->getLastActionName() << '\n';
	if (pipeline && pipeline->isEmpty())
	{
//		std::cout << position_analyze.getValue()[0] << "\n";
		Position pos(position_analyze.getValue()[0]);

		destination = p3dx_positon_analyze.getValue()[0];
//		std::cout << destination << "\n";
//		if (dif_vector.abs() < distance_threshold)
//		{
//			if (state == 1)
//			{
//				destination.setPosition(2, 2, 0.1387);
//				state = 2;
//			}
//			else if (state == 2)
//			{
//				destination.setPosition(2, -2, 0.1387);
//				state = 3;
//			}
//			else if (state == 3)
//			{
//				destination.setPosition(-2, 2, 0.1387);
//				state = 4;
//			}
//			else if (state == 4)
//			{
//				destination.setPosition(-2, -2, 0.1387);
//				state = 1;
//			}
//		}

//		std::cout << position_analyze.getValue()[0] << '\n';
//		std::cout << orientation_analyze.getValue()[0] << '\n';

		std::shared_ptr<Action> go_to_origin(new GoToPosition("GoToPosition", 1, pipeline, position_analyze.getValue()[0],
		                                                      orientation_analyze.getValue()[0], destination));
		pipeline->push(go_to_origin);


//		std::cout << position_analyze.getValue()[0] << "\n" << orientation_analyze.getValue()[0] << "\n";
	}

}
