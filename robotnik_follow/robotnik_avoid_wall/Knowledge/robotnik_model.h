//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIONEER_PIONEER_P_3_DX_MODEL_H_
#define PIONEER_PIONEER_P_3_DX_MODEL_H_

#include <string>
#include <vector>

#include <Knowledge/robot_model.h>
#include <Util/position.h>
#include <Util/orientation.h>

class RobotnikModel : public RobotModel
{
private:
	Position robot_position;
	Orientation robot_orientation;

public:
	RobotnikModel();

	Position getRobotPosition();

	Orientation getRobotOrientation();

};

#endif // PIONEER_PIONEER_P_3_DX_MODEL_H_
