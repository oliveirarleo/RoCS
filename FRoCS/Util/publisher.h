//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_PUBLISHER_H_
#define ARCH_PUBLISHER_H_

#include "observer.h"

template<typename Value>
class Publisher
{
protected:
	std::vector<Observer<Value> *> observers;
public:
	Publisher()
	{
	}

	void attach(Observer<Value> *observer)
	{
		observers.push_back(observer);
	}

	void detach(Observer<Value> *observer)
	{
		observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
	}

	void publish(Value value)
	{
		typename std::vector<Observer<Value> *>::const_iterator iter;
		for (iter = observers.begin(); iter != observers.end(); ++iter)
		{
			if (*iter != 0)
			{
				(*iter)->update(value);
			}
		}
	}
};


#endif // ARCH_PUBLISHER_H_
