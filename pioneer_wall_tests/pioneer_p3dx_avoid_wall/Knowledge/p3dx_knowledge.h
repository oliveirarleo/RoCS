//
// Created by leonardo on 16/11/18.
//

#ifndef PIONEER_P3DX_KNOWLEDGE_H
#define PIONEER_P3DX_KNOWLEDGE_H


#include <Knowledge/knowledge.h>
#include "../Connection/connection.h"
#include "pioneer_p3dx_model.h"
#include "avoid_wall_model.h"

class P3DXKnowledge : public Knowledge
{
private:
	Connection connection;
	PioneerP3DXModel pioneer_p3dx_model;
	AvoidWallModel avoid_wall_model;

public:
	P3DXKnowledge();

	Connection &getConnection();

	PioneerP3DXModel &getPioneerP3DXModel();

	AvoidWallModel &getAvoidWallModel();

};


#endif //PIONEER_P3DX_KNOWLEDGE_H
