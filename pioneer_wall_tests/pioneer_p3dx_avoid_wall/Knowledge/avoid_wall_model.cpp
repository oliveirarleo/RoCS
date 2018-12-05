//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include <iostream>
#include "avoid_wall_model.h"
#include "pioneer_p3dx_model.h"


AvoidWallModel::AvoidWallModel()
	:ReactiveModel()
{
}


AvoidWallModel::AvoidWallModel(Pipeline *pipeline)
	:ReactiveModel(pipeline)
{
}

void AvoidWallModel::react()
{
		int count = 0;
		for (int i = 2; i < 7; ++i)
		{
			Position coord;
//			sonars[i].getData(coord);
			double dist = coord.getZ();
			if (coord.isValid() && (dist < 0.8))
			{
				count++;
			}
		}

		if (count > 3)
		{
//			AvoidWall aw{15, knowledge, wheels, sonars};
//			pipeline.push(&aw);
		}

}



