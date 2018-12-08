//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIONEER_AVOID_WALL_MODEL_H_
#define PIONEER_AVOID_WALL_MODEL_H_

#include <Knowledge/reactive_model.h>
#include "../Sensors/range_vrep_sensor.h"
#include "../Actuators/wheel_vrep.h"
#include "../Monitor/range_vrep_monitor.h"

class AvoidWallModel : public ReactiveModel<std::vector<Position>>
{
private:
	double no_detection_distance;
	double min_detection_distance;
	double base_speed;
	std::vector< double > left_braitenberg;
	std::vector< double > right_braitenberg;
public:
	AvoidWallModel();

	explicit AvoidWallModel(Pipeline *pipeline);

	void react() override;


};


#endif // PIONEER_AVOID_WALL_MODEL_H_
