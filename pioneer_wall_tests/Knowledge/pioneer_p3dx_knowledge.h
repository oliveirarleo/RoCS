//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIONEER_P3DX_KNOWLEDGE_H
#define PIONEER_P3DX_KNOWLEDGE_H


#include <Knowledge/knowledge.h>
#include "../Connection/p3dx_connection.h"
#include "pioneer_p3dx_model.h"
#include "avoid_wall_model.h"

class P3DXKnowledge : public Knowledge
{
private:
	P3DXConnection connection;
	PioneerP3DXModel pioneer_p3dx_model;
	AvoidWallModel avoid_wall_model;

public:
	P3DXKnowledge();

	P3DXConnection &getConnection();

	PioneerP3DXModel &getPioneerP3DXModel();

	AvoidWallModel &getAvoidWallModel();

};


#endif //PIONEER_P3DX_KNOWLEDGE_H
