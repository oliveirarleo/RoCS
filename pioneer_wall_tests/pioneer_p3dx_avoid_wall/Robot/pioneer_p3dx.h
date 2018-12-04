//
// Created by leonardo on 16/11/18.
//

#ifndef PIONEER_PIONEER_P3DX_H
#define PIONEER_PIONEER_P3DX_H


#include <Robot/robot.h>
#include "../Knowledge/p3dx_knowledge.h"
#include "../Knowledge/avoid_wall_model.h"


class PioneerP3DX : public Robot
{
private:
	std::vector<RangeVREPSensor> sonars;
	std::vector<WheelVREP> wheels;

	P3DXKnowledge knowledge;
	AvoidWallModel avoid_wall_model;

public:
	PioneerP3DX();

	void run();

};


#endif //PIONEER_PIONEER_P_3_DX_H
