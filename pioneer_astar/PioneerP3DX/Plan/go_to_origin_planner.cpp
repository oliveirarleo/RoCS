//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include <remoteApi/extApiPlatform.h>
#include <cmath>
#include "go_to_origin_planner.h"
#include "../Knowledge/RobotModels/pioneer_p3dx_model.h"
#include "../Execute/Actions/turn_angle.h"
#include "../Execute/Actions/set_wheel_speed.h"
#include "../Execute/Actions/go_to_origin.h"

GoToOriginPlanner::GoToOriginPlanner(RobotModel &robot_, Pipeline &pipeline_, PassOrientation &pass_orientation_, PassPosition &pass_position_)
				: Planner(robot_, pipeline_), pass_orientation(pass_orientation_), pass_position(pass_position_),
					wheels(((PioneerP3DXModel &) robot).getWheels())
{

}

void GoToOriginPlanner::run()
{
	while (running)
	{
		Position pos = pass_position.getValue()[0];
		EulerAngle angle;


		if(pipeline.isEmpty())
		{
			GoToOrigin go_to_origin_action{robot, wheels, pass_orientation};
			pipeline.push(&go_to_origin_action);
		}


		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}

}