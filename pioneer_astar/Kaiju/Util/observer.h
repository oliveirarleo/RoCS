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

public:
	Observer(Value value);

	Observer();

	Value getValue();

	void printValue();

	void update(Value value);
};

// CONSTRUCTORS
template<typename Value>
Observer<Value>::Observer(Value value) : value(value)
{
}

template<typename Value>
Observer<Value>::Observer() : value{0}
{
}

// GET VALUE
template<typename Value>
Value Observer<Value>::getValue()
{
	return value;
}

// PRINT VALUE
template<typename Value>
void Observer<Value>::printValue()
{
	std::cout << "value is: " << value << std::endl;
}

// UPDATE
template<typename Value>
void Observer<Value>::update(Value value)
{
//	std::cout << "Updating value from " << this->value << " to " << value << std::endl;
	Observer::value = value;
}


#endif // ARCH_OBSERVER_H_
