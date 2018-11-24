//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIONEER_EULER_ANGLE_H_
#define PIONEER_EULER_ANGLE_H_


#include <ostream>

class EulerAngle
{
	double alpha;
	double beta;
	double gama;
	bool valid;
public:
	EulerAngle(double alpha, double beta, double gama);

	EulerAngle();

	void setEulerAngle(double alpha, double beta, double gama);

	friend std::ostream &operator<<(std::ostream &os, const EulerAngle &angle);

	double getAlpha() const;

	void setAlpha(double alpha);

	double getBeta() const;

	void setBeta(double beta);

	double getGama() const;

	void setGama(double gama);

	bool isValid() const;

	void setValid(bool valid);

};


#endif // PIONEER_EULER_ANGLE_H_
