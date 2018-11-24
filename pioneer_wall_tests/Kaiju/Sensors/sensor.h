//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ROCS_SENSOR_H_
#define ROCS_SENSOR_H_

#include <ostream>
#include "Util/position.h"

template<typename Value>
class Sensor
{
protected:
	std::string name;
	double weight;
	Position position;
	int bandwidth;

public:
	Sensor(std::string name, double weight_, Position position_, int bandwidth_) :
		name(std::move(name)), weight(weight_), position(position_), bandwidth(bandwidth_)
	{
	}

	Sensor(std::string name_) : name(std::move(name_)), weight{0}, position{}, bandwidth{50}
	{
	}

	friend std::ostream &operator<<(std::ostream &os, const Sensor<Value> &sensor)
	{
		os << "Name: " << sensor.name << " Weight: " << sensor.weight << " Position: " << sensor.position << " Bandwidth: "
			 << sensor.bandwidth << " ";
		return os;
	}

	virtual bool getData(Value &value) = 0;

	const std::string &getName() const
	{
		return name;
	}

	void setName(const std::string &name)
	{
		Sensor::name = name;
	}

	double getWeight() const
	{
		return weight;
	}

	void setWeight(double weight)
	{
		Sensor::weight = weight;
	}

	const Position &getPosition() const
	{
		return position;
	}

	void setPosition(const Position &position)
	{
		Sensor::position = position;
	}

	int getBandwidth() const
	{
		return bandwidth;
	}

	void setBandwidth(int bandwidth)
	{
		Sensor::bandwidth = bandwidth;
	}
};


#endif // ROCS_SENSOR_H_
