//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_POSITION_H_
#define ARCH_POSITION_H_

#include <ostream>
#include <cmath>

class Position
{
protected:
	double x;
	double y;
	double z;
	bool valid;

public:
	Position(double x_, double y_, double z_)
	{
		x = x_;
		y = y_;
		z = z_;
		valid = true;
	}

	Position(double x_, double y_, double z_, bool valid_)
	{
		x = x_;
		y = y_;
		z = z_;
		valid = valid_;
	}

	Position():x{0}, y{0}, z{0}, valid(false)
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

	Position operator+(Position &pos)
	{
		return Position(this->x + pos.getX(), this->y + pos.getY(), this->z + pos.getZ(), this->valid && pos.isValid());
	}


	Position operator-(Position &pos)
	{
		return Position(this->x - pos.getX(), this->y - pos.getY(), this->z - pos.getZ(), this->valid && pos.isValid());
	}

	bool close(double x_, double y_, double threshold)
	{
		return ((fabs(x - x_) < threshold)  && (fabs(y - y_) < threshold));
	}

	double abs()
	{
		return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
	}

	double arg()
	{
		if (this->x > 0)
			return atan(this->y / this->x);
		else if(this->x < 0)
		{
			if(this->y >= 0)
				return (atan(this->y / this->x) + M_PI);
			else
				return (atan(this->y / this->x) - M_PI);
		}
		else
		{
			if(this->y > 0)
				return -M_PI_2;
			else
				return M_PI_2;

		}


		return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
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
		os << "x: " << position.x << " y: " << position.y << " z: " << position.z << " valid: " << position.valid;
		return os;
	}

};

#endif //ARCH_POSITION_H_
