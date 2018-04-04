//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_MOTOR_H_
#define ARCH_MOTOR_H_

template <class T>
class Motor: public Actuator<T>
{
protected:
    double max_speed;
    double speed;

};

#endif //ARCH_MOTOR_H_
