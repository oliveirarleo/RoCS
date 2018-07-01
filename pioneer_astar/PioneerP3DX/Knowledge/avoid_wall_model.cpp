//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include "avoid_wall_model.h"
#include "../Execute/Actions/move_wheels.h"
#include "sonar_output.h"
#include "pioneer_p3dx_model.h"

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
	while (running)
	{
		//		std::cout << "running" << std::endl;
		std::vector<WheelVREP *> wheels = ((PioneerP3DXModel &) robot).getWheels();
		std::vector<RangeVREP *> sonars = ((PioneerP3DXModel &) robot).getSonars();
		for (int i = 0; i < 16; i++)
		{
			SonarOutput coord;
			sonars[i]->getData(coord);

//			sonars[i]->getData(coord);

			double dist = coord.getZ();

			if (coord.getState() && (dist < no_detection_dist))
			{

				if (dist < max_detection_dist)
				{
					dist = max_detection_dist;
				}

				detect[i] = 1 - ((dist - max_detection_dist) / (no_detection_dist - max_detection_dist));
			}
			else
				detect[i] = 0;

//			std::cout << detect[i];
		}
//		std::cout << std::endl;

		v_left = v0;
		v_right = v0;

		for (int i = 0; i < 16; i++)
		{
			v_left = v_left + braitenberg_l[i] * detect[i];
			v_right = v_right + braitenberg_r[i] * detect[i];
		}
		// atualiza velocidades dos motores
		MoveWheels mw{wheels, v_left, v_right};
		pipeline.push(&mw);

		// espera um pouco antes de reiniciar a leitura dos sensores
		std::this_thread::sleep_for(std::chrono::milliseconds(50));

	}

}
