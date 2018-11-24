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

class AvoidWallModel : public ReactiveModel
{
private:
	std::vector<RangeVREPSensor> &sonars;
	std::vector<WheelVREP> &wheels;

public:
	AvoidWallModel(Pipeline &pipeline, std::vector<RangeVREPSensor> &sonars_, std::vector<WheelVREP> &wheels_);

	void run() override;


};


#endif // PIONEER_AVOID_WALL_MODEL_H_
