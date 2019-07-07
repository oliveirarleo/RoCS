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

class RobotnikKnowledge : public Knowledge
{
private:
	Connection connection;
	RobotnikModel robot_model;

public:
	RobotnikKnowledge();

	Connection &getConnection();

	RobotnikModel &getRobotModel();


};


#endif //PIONEER_P3DX_KNOWLEDGE_H
