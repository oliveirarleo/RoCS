//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include <Util/orientation.h>
#include <cmath>
#include "turn_to_angle.h"
#include "set_wheels_speed.h"


TurnToAngle::TurnToAngle(const std::string &name_, double value_, Pipeline *pipeline_, Orientation &orientation_, double desired_orientation_, bool clockwise_)
	:Action(name_, value_, pipeline_), orientation(orientation_), desired_orientation(desired_orientation_),
	 clockwise(clockwise_)
{
}

void TurnToAngle::act()
{
	if (orientation.isValid())
	{
		double base_speed = 0;
		double speed = 0.8;

		double an = desired_orientation - orientation.getGamma();
		if (an <= -M_PI)
			an += 2 * M_PI;
		if (an > M_PI)
			an -= 2 * M_PI;

		double calc_speed = ((an) / (2));

//		std::cout << "des " << desired_orientation << "\n";
//		std::cout << "rob " << orientation.getGamma() << "\n";
//		std::cout << "an " << an << " sp " << calc_speed << "\n";

		calc_speed = fabs(calc_speed);
		if (calc_speed <= speed)
			speed = calc_speed;

//		std::cout << "turn\n";
		if (clockwise)
		{
			std::shared_ptr<Action> turn(new SetWheelsSpeed("Turn", 1, pipeline, base_speed - speed, base_speed + speed));
			pipeline->push(turn);
		}
		else
		{
			std::shared_ptr<Action> turn(new SetWheelsSpeed("Turn", 1, pipeline, speed, -speed));
			pipeline->push(turn);
		}

//		left_wheel->setSpeed(base_speed-final_speed);
//		right_wheel->setSpeed(base_speed + final_speed);
	}
}

void TurnToAngle::setActuators(std::vector<std::vector<Actuator *> > &actuators)
{
	Action::actuators = actuators;
	left_wheel = (WheelVREP *) (actuators[0][0]);
	right_wheel = (WheelVREP *) (actuators[0][1]);
}



