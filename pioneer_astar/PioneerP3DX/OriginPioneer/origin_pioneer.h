//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIONEER_A_STAR_PIONEER_H_
#define PIONEER_A_STAR_PIONEER_H_


#include "../Knowledge/RobotModels/pioneer_p3dx_model.h"

class OriginPioneer
{
public:
	PioneerP3DXModel p3dx_model;

public:
	OriginPioneer();

	virtual ~OriginPioneer();
};


#endif // PIONEER_A_STAR_PIONEER_H_
