//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_SONAR_H_
#define ARCH_SONAR_H_

#include <ostream>
#include "range.h"

template<typename Value>
class Sonar : public Range
{
public:
	Sonar(std::string name_, double weight_, Position position_, double bandwidth_, double max_range_, double resolution_,
				double fov_angle_, double beam_angle_, double scan_interval_) :
					Range<Value>(name_, weight_, position_, bandwidth_, max_range_, resolution_, fov_angle_, beam_angle_,
									 scan_interval_)
	{

	}

	Sonar(std::string name) : Range<Value>(name)
	{
	}

	friend std::ostream &operator<<(std::ostream &os, const Sonar &sonar)
	{
		os << static_cast<const Range &>(sonar);
		return os;
	}
};


#endif //ARCH_SONAR_H_
