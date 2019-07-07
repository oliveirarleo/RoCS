//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include <iostream>
#include <iomanip>
#include "avoid_wall_model.h"
#include "pioneer_p3dx_model.h"
#include "../Execute/Actions/set_wheels_speed.h"


AvoidWallModel::AvoidWallModel()
	:ReactiveModel(), no_detection_distance(0.3), min_detection_distance(0.1), base_speed(1.5),
	 left_braitenberg{-0.2, -0.4, -0.6, -0.8, -1, -1.2, -1.4, -1.6},
	 right_braitenberg{-1.6, -1.4, -1.2, -1, -0.8, -0.6, -0.4, -0.2}
{
}


AvoidWallModel::AvoidWallModel(Pipeline *pipeline)
	:ReactiveModel(pipeline)
{

}

void AvoidWallModel::react()
{
	double left_v = base_speed;
	double right_v = base_speed;
	for (int i = 0; i < 8; ++i)
	{
		double d = this->observed_value[i].getZ();
		if (this->observed_value[i].isValid() && d < no_detection_distance)
		{
			if (d > min_detection_distance)
				d = min_detection_distance;
			double detection = 1 - ((d - min_detection_distance) / (no_detection_distance - min_detection_distance));
			left_v += left_braitenberg[i] * detection;
			right_v += right_braitenberg[i] * detection;
		}
	}

	double threshold = 0.1;
	if (fabs(left_v - base_speed) > threshold || fabs(right_v - base_speed) > threshold)
	{
		std::shared_ptr<Action> set_speed(new SetWheelsSpeed("Reaction Braitenberg", 60, pipeline, left_v, right_v));
		pipeline->push(set_speed);
	}


//	for(Position p : this->observed_value)
//	{
//		std::cout << std::fixed  << std::setprecision(3) << p.getZ() << " ";
//	}
//	std::cout << "\n";

}



