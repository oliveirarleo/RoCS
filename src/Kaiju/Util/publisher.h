//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_PUBLISHER_H_
#define ARCH_PUBLISHER_H_

#include <vector>
#include "observer.h"

class Publisher
{
private:
	std::vector<Observer *> observers;
public:
	Publisher(const std::vector<Observer *> &observers) : observers(observers)
	{
	}

	virtual void attach(Observer observer) = 0;
};


#endif // ARCH_PUBLISHER_H_
