//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_OBSERVER_H_
#define ARCH_OBSERVER_H_


#include <iostream>
#include <vector>
#include "observer.h"


template<typename Value>
class Observer
{
protected:
	Value value;
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
		os << "value: " << observer.value;
		return os;
	}
};

// CONSTRUCTORS
//template<typename Value>
//Observer<Value>::Observer(Value value) : value(value), write_mu{}, ul{write_mu, std::defer_lock}
//{
//}



template<typename Value>
Observer<Value>::Observer() : value{}, write_mu{}, ul{write_mu, std::defer_lock}
{
}

// GET VALUE
template<typename Value>
Value Observer<Value>::getValue()
{
	while (ul.owns_lock());
	return value;
}

// PRINT VALUE
template<typename Value>
void Observer<Value>::printValue()
{
//	std::cout << "value is: " << value << std::endl;
}

// UPDATE
template<typename Value>
void Observer<Value>::update(Value value)
{
//	std::cout << "Updating value from " << this->value << " to " << value << std::endl;
	ul.lock();
	Observer::value = value;
	ul.unlock();
}


#endif // ARCH_OBSERVER_H_
