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
#include <Util/observer.h>

class PioneerP3DXModel : public RobotModel, public Observer<std::vector<Orientation> >, public Observer<std::vector<Position> >
{
private:
	Position robot_position;
	Orientation robot_orientation;

public:
	PioneerP3DXModel();

	Position getPosition();

	Orientation getOrientation();

};

#endif // PIONEER_PIONEER_P_3_DX_MODEL_H_
