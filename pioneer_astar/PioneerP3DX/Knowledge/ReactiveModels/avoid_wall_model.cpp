//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include <iostream>
#include "avoid_wall_model.h"
#include "../../Execute/Actions/set_wheel_speed.h"
#include "../RobotModels/pioneer_p3dx_model.h"
#include "../../Execute/Actions/avoid_wall.h"


AvoidWallModel::AvoidWallModel(RobotModel &robot, Pipeline &pipeline)
				: ReactiveModel(robot, pipeline), no_detection_dist(0.5), max_detection_dist(0.2),
					detect{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					braitenberg_l{-0.2, -0.4, -0.6, -0.8, -1, -1.2, -1.4, -1.6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
					braitenberg_r{-1.6, -1.4, -1.2, -1, -0.8, -0.6, -0.4, -0.2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
					v0(2), v_left(0), v_right(0)
{
}

void AvoidWallModel::run()
{
	//		std::cout << "running" << std::endl;

	while (running)
	{
		std::vector<WheelVREP *>& wheels = ((PioneerP3DXModel &) robot).getWheels();
		std::vector<RangeVREP *>& sonars = ((PioneerP3DXModel &) robot).getSonars();
		int count = 0;
		for (int i = 2; i < 7; ++i)
		{
			RangeOutput coord;
			sonars[i]->getData(coord);
			double dist = coord.getZ();
			if (coord.getState() && (dist < no_detection_dist))
			{
				count++;
			}
		}

		if(count > 3)
		{
			std::cout<< "ENTROOO"<<std::endl;
			AvoidWall aw{15, robot, wheels, sonars};
			pipeline.push(&aw);
		}


		// espera um pouco antes de reiniciar a leitura dos sensores
		std::this_thread::sleep_for(std::chrono::milliseconds(50));

	}

}
