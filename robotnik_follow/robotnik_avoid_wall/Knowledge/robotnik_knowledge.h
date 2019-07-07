//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIONEER_P3DX_KNOWLEDGE_H
#define PIONEER_P3DX_KNOWLEDGE_H


#include <Knowledge/knowledge.h>
#include "../Connection/connection.h"
#include "robotnik_model.h"
#include "avoid_wall_model.h"

class RobotnikKnowledge : public Knowledge
{
private:
	Connection connection;
	RobotnikModel robot_model;
	AvoidWallModel avoid_wall_model;
	Pipeline *pipeline;

public:
	RobotnikKnowledge();

	Connection &getConnection();

	RobotnikModel &getRobotModel();

	AvoidWallModel &getAvoidWallModel();

	void setPipeline(Pipeline *pipeline_);

	std::shared_ptr<Action> getCurrentAction();

	Position getRobotPosition();

	Orientation getRobotOrientation();


};


#endif //PIONEER_P3DX_KNOWLEDGE_H
