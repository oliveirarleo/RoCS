//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_SONAR_H_
#define ARCH_SONAR_H_

#include <ostream>
#include "range.h"

template<class T>
class Sonar : public Range<T>
{
public:
	friend std::ostream &operator<<(std::ostream &os, const Sonar<T> &sonar)
	{
		os << static_cast< const Range<T> & >(sonar);
		return os;
	}

	Sonar(double weight_, Position position_, double bandwidth_, double max_range_, double resolution_,
		  double fov_angle_, double beam_angle_, double scan_interval_) :
			Range<T>(weight_, position_, bandwidth_, max_range_, resolution_, fov_angle_, beam_angle_, scan_interval_)
	{

	}
};


#endif //ARCH_SONAR_H_
