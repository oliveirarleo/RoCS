//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_FOV_H_
#define ARCH_FOV_H_

class FOV
{
private:
	double starting_angle;
	double ending_angle;

public:
	FOV(double start, double end) :
					starting_angle(start),
					ending_angle(end)
	{
	}
};

#endif //ARCH_FOV_H_
