//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include "robotnik_knowledge.h"

RobotnikKnowledge::RobotnikKnowledge():connection{}, robot_model{}
{
}

Connection &RobotnikKnowledge::getConnection()
{
	return connection;
}

RobotnikModel &RobotnikKnowledge::getRobotModel()
{
	return robot_model;
}
