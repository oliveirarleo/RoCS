//
// Created by leonardo on 16/11/18.
//

#include "p3dx_knowledge.h"

P3DXKnowledge::P3DXKnowledge():connection{}, pioneer_p3dx_model{}, avoid_wall_model{}
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
