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

AvoidWallModel &RobotnikKnowledge::getAvoidWallModel()
{
	return avoid_wall_model;
}

void RobotnikKnowledge::setPipeline(Pipeline *pipeline_)
{
	RobotnikKnowledge::pipeline = pipeline_;
}


std::shared_ptr<Action> RobotnikKnowledge::getCurrentAction()
{
	if (pipeline != nullptr)
		return  pipeline->getAction();
	else
	{
		return nullptr;
	}

}

Position RobotnikKnowledge::getRobotPosition()
{

	return robot_model.getRobotPosition();
}

Orientation RobotnikKnowledge::getRobotOrientation()
{
	return robot_model.getRobotOrientation();
}




