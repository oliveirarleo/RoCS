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
//#include <Knowledge/knowledge.h>

class Knowledge;

class RobotModel
{
protected:
	std::string name;
	Knowledge &knowledge;
	Position position;
	Orientation orientation;



public:

	RobotModel(std::string name_, Knowledge &knowledge_)
		:name(std::move(name)), knowledge(knowledge_), position(), orientation()
	{
	}

	RobotModel(std::string name_, Knowledge &knowledge_, Position position_, Orientation orientation_)
		:name(std::move(name)), knowledge(knowledge_), position(position_), orientation(orientation_)
	{
	}


};

#endif //ARCH_ROBOT_MODEL_H_
