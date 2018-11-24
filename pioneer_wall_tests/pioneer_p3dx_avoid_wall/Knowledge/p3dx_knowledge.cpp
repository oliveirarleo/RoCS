//
// Created by leonardo on 16/11/18.
//

#include "p3dx_knowledge.h"

P3DXKnowledge::P3DXKnowledge() : connection{}, pioneer_p3dx_model{*this}
{
}

const Connection &P3DXKnowledge::getConnection() const
{
	return connection;
}

const PioneerP3DXModel &P3DXKnowledge::getPioneer_p3dx_model() const
{
	return pioneer_p3dx_model;
}
