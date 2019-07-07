//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include "p3dx_knowledge.h"

P3DXKnowledge::P3DXKnowledge():connection{}, pioneer_p3dx_model{}, avoid_wall_model{}, pipeline(nullptr)
{
}

Connection &P3DXKnowledge::getConnection()
{
	return connection;
}

PioneerP3DXModel &P3DXKnowledge::getPioneerP3DXModel()
{
	return pioneer_p3dx_model;
}

AvoidWallModel &P3DXKnowledge::getAvoidWallModel()
{
	return avoid_wall_model;
}

void P3DXKnowledge::setPipeline(Pipeline *pipeline_)
{
	P3DXKnowledge::pipeline = pipeline_;
}

std::shared_ptr<Action> P3DXKnowledge::getCurrentAction()
{
	if (pipeline != nullptr)
		return  pipeline->getAction();
	else
	{
		return nullptr;
	}

}

Position P3DXKnowledge::getRobotPosition()
{

	return pioneer_p3dx_model.getPosition();
}

Orientation P3DXKnowledge::getRobotOrientation()
{
	return pioneer_p3dx_model.getOrientation();
}
