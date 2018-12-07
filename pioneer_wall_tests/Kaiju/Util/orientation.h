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
	double gamma;
	bool valid;

public:
	Orientation(double alpha_, double beta_, double gamma_)
	{
		if (gamma_ > 3.14 || gamma_ < -3.14)
		{
			valid = false;
		}

		else
		{
			alpha = alpha_;
			beta = beta_;
			gamma = gamma_;
			valid = true;
		}
	}

	Orientation(double alpha_, double beta_, double gamma_, bool valid_)
	{
		if (gamma_ > 3.14 || gamma_ < -3.14)
		{
			valid = false;
		}

		else
		{
			alpha = alpha_;
			beta = beta_;
			gamma = gamma_;
			valid = valid_;
		}
	}

	Orientation() : alpha(0), beta(0), gamma(0), valid(false)
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
			gamma = gama_;
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

	double getGamma() const
	{
		return gamma;
	}

	void setGamma(double gama)
	{
		Orientation::gamma = gama;
	}

	bool isValid() const
	{
		return valid;
	}

	void setValid(bool valid)
	{
		Orientation::valid = valid;
	}

	Orientation operator+(Orientation &pos)
	{
		return Orientation(this->alpha + pos.getAlpha(), this->beta + pos.getBeta(), this->gamma + pos.getGamma(),this->valid && pos.isValid());
	}


	Orientation operator-(Orientation &pos)
	{
		return Orientation(this->alpha - pos.getAlpha(), this->beta - pos.getBeta(), this->gamma - pos.getGamma(), this->valid && pos.isValid());
	}


	friend std::ostream &operator<<(std::ostream &os, const Orientation &angle)
	{
		os << "alpha: " << angle.alpha << " beta: " << angle.beta << " gamma: " << angle.gamma << " valid: " << angle.valid;
		return os;
	}
};

#endif //PIONEER_ORIENTATION_H