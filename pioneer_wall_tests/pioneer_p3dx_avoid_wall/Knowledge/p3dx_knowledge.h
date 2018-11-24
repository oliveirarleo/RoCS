//
// Created by leonardo on 16/11/18.
//

#ifndef PIONEER_P_3_DX_KNOWLEDGE_H
#define PIONEER_P_3_DX_KNOWLEDGE_H


#include <Knowledge/knowledge.h>
#include "../Connection/connection.h"
#include "pioneer_p3dx_model.h"
#include "avoid_wall_model.h"

class P3DXKnowledge : public Knowledge
{
private:
	Connection connection;
	PioneerP3DXModel pioneer_p3dx_model;

public:
	P3DXKnowledge();

	const Connection &getConnection() const;

	const PioneerP3DXModel &getPioneer_p3dx_model() const;

	const AvoidWallModel &getAvoid_wall_model() const;
};


#endif //PIONEER_P_3_DX_KNOWLEDGE_H
