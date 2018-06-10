//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include <remoteApi/extApiPlatform.h>
#include "brait_plan.h"
#include "../Knowledge/pioneer_p3dx_model.h"
#include "../Execute/Actions/move_wheels.h"

BraitPlan::BraitPlan(RobotModel &robot, std::vector<PassSonarPosition *> &sonar_analyze_observers, Pipeline& pipeline_)
				: Planner(robot), sonar_analyze_observers(sonar_analyze_observers), pipeline(pipeline_), running(true), no_detection_dist(0.5),
					max_detection_dist(0.2), detect{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					braitenberg_l{-0.2, -0.4, -0.6, -0.8, -1, -1.2, -1.4, -1.6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
					braitenberg_r{-1.6, -1.4, -1.2, -1, -0.8, -0.6, -0.4, -0.2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
					v0(2), v_left(0), v_right(0)
{
}

void BraitPlan::run()
{
	std::vector<WheelVREP *> wheels = ((PioneerP3DXModel &) robot).getWheels();
	std::vector<SonarVREP *> sonars = ((PioneerP3DXModel &) robot).getSonars();
	while (running && ((PioneerP3DXModel &) robot).getConnection().isConnected())
	{
//		std::cout << "running" << std::endl;
		for (int i = 0; i < 16; i++)
		{
			SonarOutput coord = sonar_analyze_observers[i]->getValue();

//			SonarOutput coord;
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
//		((PioneerP3DXModel&)robot).getRobotPosition();
		// atualiza velocidades dos motores
		MoveWheels mw{wheels , v_left, v_right};
		pipeline.push(&mw);
//		wheels[0]->setSpeed(v_left);
//		wheels[1]->setSpeed(v_right);



//		for (int i = 0; i < 16; i++)
//		{
//			std::lock_guard<std::mutex> lg(mu);
////			std::cout << name << std::endl;
//
//			Position coord = sonar_analyze_observers[i]->getValue();
//			std::cout << i << ": " << coord << std::endl;
//		}

		// espera um pouco antes de reiniciar a leitura dos sensores
		extApi_sleepMs(250);

	}

}