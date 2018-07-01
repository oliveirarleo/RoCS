//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIONEER_AVOID_WALL_H_
#define PIONEER_AVOID_WALL_H_

#include <Knowledge/reactive_model.h>

class AvoidWallModel : public ReactiveModel
{
public:
	double no_detection_dist;
	double max_detection_dist;
	std::vector<double> detect;
	std::vector<double> braitenberg_l;
	std::vector<double> braitenberg_r;
	double v0;

	AvoidWallModel(RobotModel &robot, Pipeline &pipeline);

	double v_left;

	void run() override;

	double v_right;


};


#endif // PIONEER_AVOID_WALL_H_
