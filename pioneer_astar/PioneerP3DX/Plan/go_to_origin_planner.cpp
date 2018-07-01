//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include <remoteApi/extApiPlatform.h>
#include "go_to_origin_planner.h"
#include "../Knowledge/pioneer_p3dx_model.h"
#include "../Execute/Actions/move_wheels.h"

GoToOriginPlanner::GoToOriginPlanner(RobotModel &robot_, Pipeline& pipeline_, std::vector<PassSonarPosition*> sonar_analyze_observers_)
				: Planner(robot_, pipeline_), sonar_analyze_observers(sonar_analyze_observers_)
{
}

void GoToOriginPlanner::run()
{
	while (running && ((PioneerP3DXModel &) robot).getConnection().isConnected())
	{
//		if(pipeline.isEmpty())
//		{
//
//			pipeline.push();
//		}


	}

}