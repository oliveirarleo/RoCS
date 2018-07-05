//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIONEER_AVOID_WALL_H_
#define PIONEER_AVOID_WALL_H_


#include <Execute/action.h>
#include <Knowledge/robot_model.h>
#include "../../Actuators/wheel_vrep.h"
#include "../../Sensors/range_vrep.h"

class AvoidWall: public Action
{
private:

	RobotModel& robot;
	std::vector < WheelVREP *>& wheels;
	std::vector < RangeVREP *>& ranges;
public:
	AvoidWall(double value_, RobotModel &robot,  std::vector<WheelVREP *> &wheels,  std::vector<RangeVREP *> &ranges);

public:
	void act() override;

};


#endif // PIONEER_AVOID_WALL_H_
