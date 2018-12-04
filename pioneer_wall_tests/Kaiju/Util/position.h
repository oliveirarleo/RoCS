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
protected:
	double x;
	double y;
	double z;
	bool valid;

public:
	Position(double x_, double y_, double z_, bool valid_)
	{
		x = x_;
		y = y_;
		z = z_;
		valid = valid_;
	}

	Position() : x{0}, y{0}, z{0}, valid(false)
	{
	}

	void setPosition(double x_, double y_, double z_)
	{
		x = x_;
		y = y_;
		z = z_;
		valid = true;
	}

	void setPosition(double x_, double y_, double z_, bool valid_)
	{
		x = x_;
		y = y_;
		z = z_;
		valid = valid_;
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

	bool isValid() const
	{
		return valid;
	}

	void setValid(bool valid)
	{
		Position::valid = valid;
	}

	friend std::ostream &operator<<(std::ostream &os, const Position &position)
	{
		os << "x: " << position.x << " y: " << position.y << " z: " << position.z << " ";
		return os;
	}
};

#endif //ARCH_POSITION_H_
