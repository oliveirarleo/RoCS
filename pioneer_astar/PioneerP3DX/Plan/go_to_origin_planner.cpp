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

GoToOriginPlanner::GoToOriginPlanner(RobotModel &robot_, Pipeline &pipeline_, PassOrientation &pass_orientation_, PassPosition &pass_position_)
				: Planner(robot_, pipeline_), pass_orientation(pass_orientation_), pass_position(pass_position_),
					wheels(((PioneerP3DXModel &) robot).getWheels())
{

}

void GoToOriginPlanner::run()
{
	while (running)
	{
//		std::cout << pass_orientation.getValue()[0] << "\n";
//		std::cout << pass_position.getValue()[0] << "\n";

		Position pos = pass_position.getValue()[0];
		EulerAngle angle = pass_orientation.getValue()[0];


		double des_angle = (5.3);
		if (angle.isValid())
		{
			TurnAngle ta{robot, wheels, angle.getGama(), des_angle};
			pipeline.push(&ta);
		}



//		if(pipeline.isEmpty())
//		{
//			GoToOrigin go_to_origin_action{robot, wheels, pass_position.getValue()[0],  pass_orientation.getValue()[0]};
//			pipeline.push(&go_to_origin_action);
//		}


		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}

}