//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIONEER_SONAR_OUTPUT_H_
#define PIONEER_SONAR_OUTPUT_H_


#include <Knowledge/position.h>

class RangeOutput : public Position
{
public:
	bool state;

	RangeOutput() : Position{}, state{false}
	{
	}

	RangeOutput(double x_, double y_, double z_, bool state_) : Position(x_, y_, z_), state(state_)
	{
	}

	void setSonarOutput(double x_, double y_, double z_, bool state_)
	{
		x = x_;
		y = y_;
		z = z_;
		state = state_;
	}

	int getState()
	{
		return state;
	}

	void setState(int state)
	{
		RangeOutput::state = state;
	}
};


#endif // PIONEER_SONAR_OUTPUT_H_
