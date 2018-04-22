//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_ACTUATOR_ACCESSOR_H_
#define ARCH_ACTUATOR_ACCESSOR_H_

template<class T>

class ActuatorAccessor
{
public:
	virtual void setData(T) = 0;
};

#endif //ARCH_ACTUATOR_ACCESSOR_H_
