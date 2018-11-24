//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_OBSERVER_H_
#define ARCH_OBSERVER_H_


#include <iostream>
#include <vector>
#include <mutex>
#include "observer.h"


template<typename Value>
class Observer
{
protected:
	Value observed_value;
	std::mutex write_mu;
	std::unique_lock<std::mutex> ul;


public:
	Observer(Value value);

	Observer();

	Value getValue();

	void printValue();

	void update(Value value);

	friend std::ostream &operator<<(std::ostream &os, const Observer<Value> &observer)
	{
		os << "value: " << observer.observed_value;
		return os;
	}
};


template<typename Value>
Observer<Value>::Observer() : observed_value{}, write_mu{}, ul{write_mu, std::defer_lock}
{
}

// GET VALUE
template<typename Value>
Value Observer<Value>::getValue()
{
	while (ul.owns_lock());
	return observed_value;
}

// PRINT VALUE
template<typename Value>
void Observer<Value>::printValue()
{
	std::cout << "value is: " << observed_value << std::endl;
}

// UPDATE
template<typename Value>
void Observer<Value>::update(Value value)
{
	ul.lock();
	Observer::observed_value = value;
	ul.unlock();
}


#endif // ARCH_OBSERVER_H_
