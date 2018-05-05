//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_POSITION_H_
#define ARCH_POSITION_H_

#include <ostream>

class Position
{
private:
	double x;
	double y;
	double z;

public:
	Position(double x_, double y_, double z_)
	{
		x = x_;
		y = y_;
		z = z_;
	}

	friend std::ostream &operator<<(std::ostream &os, const Position &position)
	{
		os << "x: " << position.x << " y: " << position.y << " z: " << position.z << " ";
		return os;
	}

	void setPosition(double x_, double y_, double z_)
	{
		x = x_;
		y = y_;
		z = z_;
	}

	double getX()
	{
		return x;
	}

	double getY()
	{
		return y;
	}

	double getZ()
	{
		return z;
	}

};

#endif //ARCH_POSITION_H_
