//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include <remoteApi/extApiPlatform.h>
#include "go_to_origin_planner.h"
#include "../Knowledge/pioneer_p3dx_model.h"
#include "../Execute/Actions/move_wheels.h"

GoToOriginPlanner::GoToOriginPlanner(RobotModel &robot_, Pipeline& pipeline_, PassOrientation& pass_orientation_)
				: Planner(robot_, pipeline_), pass_orientation(pass_orientation_)
{
}

void GoToOriginPlanner::run()
{
	while (running)
	{
//		std::cout << pass_orientation.getValue()[0] << "\n";

	}

}