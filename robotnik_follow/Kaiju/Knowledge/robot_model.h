//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_ROBOT_MODEL_H_
#define ARCH_ROBOT_MODEL_H_

#include <string>
#include <Util/position.h>
#include <Util/orientation.h>


class RobotModel
{
protected:
	std::string name;
	Position position;
	Orientation orientation;

public:

	explicit RobotModel(std::string name_)
		:name(std::move(name)), position(), orientation()
	{
	}

	RobotModel(std::string name_, Position position_, Orientation orientation_)
		:name(std::move(name)), position(position_), orientation(orientation_)
	{
	}


};

#endif //ARCH_ROBOT_MODEL_H_
