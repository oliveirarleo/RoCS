//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include "euler_angle.h"

EulerAngle::EulerAngle(double alpha, double beta, double gama) : alpha(alpha), beta(beta), gama(gama), valid(true)
{
}

EulerAngle::EulerAngle() : alpha(0), beta(0), gama(0), valid(false)
{
}

void EulerAngle::setEulerAngle(double alpha_, double beta_, double gama_)
{
	alpha = alpha_;
	beta = beta_;
	gama = gama_;
	valid = true;
}

double EulerAngle::getAlpha() const
{
	return alpha;
}

void EulerAngle::setAlpha(double alpha)
{
	EulerAngle::alpha = alpha;
}

double EulerAngle::getBeta() const
{
	return beta;
}

void EulerAngle::setBeta(double beta)
{
	EulerAngle::beta = beta;
}

double EulerAngle::getGama() const
{
	return gama;
}

void EulerAngle::setGama(double gama)
{
	EulerAngle::gama = gama;
}

std::ostream &operator<<(std::ostream &os, const EulerAngle &angle)
{
	os << "alpha: " << angle.alpha << " beta: " << angle.beta << " gama: " << angle.gama << " valid: " << angle.valid;
	return os;
}
