//
// Created by leonardo on 15/11/18.
//

#ifndef PIONEER_ORIENTATION_H
#define PIONEER_ORIENTATION_H



#include <ostream>

class Orientation
{
private:
	double alpha;
	double beta;
	double gama;
	bool valid;

public:
	Orientation(double alpha_, double beta_, double gama_)
	{
		if (gama_ > 3.14 || gama_ < -3.14)
		{
			valid = false;
		}

		else
		{
			alpha = alpha_;
			beta = beta_;
			gama = gama_;
			valid = true;
		}
	}

	Orientation() : alpha(0), beta(0), gama(0), valid(false)
	{
	}

	void setOrientation(double alpha_, double beta_, double gama_)
	{
		if (gama_ > 3.14 || gama_ < -3.14)
		{
			valid = false;
		}

		else
		{
			alpha = alpha_;
			beta = beta_;
			gama = gama_;
			valid = true;
		}
	}

	double getAlpha() const
	{
		return alpha;
	}

	void setAlpha(double alpha)
	{
		Orientation::alpha = alpha;
	}

	double getBeta() const
	{
		return beta;
	}

	void setBeta(double beta)
	{
		Orientation::beta = beta;
	}

	double getGama() const
	{
		return gama;
	}

	void setGama(double gama)
	{
		Orientation::gama = gama;
	}

	bool isValid() const
	{
		return valid;
	}

	void setValid(bool valid)
	{
		Orientation::valid = valid;
	}

	friend std::ostream &operator<<(std::ostream &os, const Orientation &angle)
	{
		os << "alpha: " << angle.alpha << " beta: " << angle.beta << " gama: " << angle.gama << " valid: " << angle.valid;
		return os;
	}
};

#endif //PIONEER_ORIENTATION_H