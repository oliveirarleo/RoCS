//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_SERVO_MOTOR_H_
#define ARCH_SERVO_MOTOR_H_

#include "motor.h"

template<class T>
class ServoMotor : public Motor
{
protected:
	double angle;
	double max_angle;
	double min_angle;
	double max_torque_low;
};

#endif //ARCH_SERVO_MOTOR_H_
