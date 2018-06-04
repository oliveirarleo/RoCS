//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_OBSERVER_H_
#define ARCH_OBSERVER_H_


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

	friend std::ostream &operator<<(std::ostream &os, const Observer<double> &observer)
	{
		os << "Value: " << observer.value;
		return os;
	}
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
Value getValue()
{
	return value;
}

// PRINT VALUE
template<typename Value>
void printValue()
{
	std::cout << "value is: " << value << std::endl;
}

// UPDATE
template<typename Value>
void update(Value value)
{
//	std::cout << "Updating value from " << this->value << " to " << value << std::endl;
	Observer::value = value;
}


#endif // ARCH_OBSERVER_H_
