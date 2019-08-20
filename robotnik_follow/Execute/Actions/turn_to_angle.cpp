//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include <Util/orientation.h>
#include <cmath>
#include "turn_to_angle.h"
#include "set_wheels_speed.h"


TurnToAngle::TurnToAngle(const std::string &name_, double value_, Pipeline *pipeline_, Orientation &orientation_, double desired_orientation_,
						 double base_speed_, double turn_speed_)
	:Action(name_, value_, pipeline_), orientation(orientation_), desired_orientation(desired_orientation_), base_speed(base_speed_), turn_speed(turn_speed_)
{
}

void TurnToAngle::act()
{
	if (orientation.isValid())
	{
//		double base_speed = 0.5;
//		double speed = 0.5;

		double an = desired_orientation - orientation.getGamma();
		if (an <= -M_PI)
			an += 2 * M_PI;
		if (an > M_PI)
			an -= 2 * M_PI;

//		an += M_PI;
//		std::cout << "des " << desired_orientation << "\n";
//		std::cout << "an " << an << "\n";

		double calc_speed = ((an) / (2));

//		std::cout << "des " << desired_orientation << "\n";
//		std::cout << "rob " << orientation.getGamma() << "\n";
//		std::cout << "an " << an << " sp " << calc_speed << "\n";

		calc_speed = fabs(calc_speed)+turn_speed*0.2;
		if (calc_speed <= turn_speed)
			turn_speed = calc_speed;

//		std::shared_ptr<Action> turn(new SetWheelsSpeed("Turn", 1, pipeline, 1, -1));
//		pipeline->push(turn);

//		std::cout << "turn\n";
		if (an > 0)
		{
			std::shared_ptr<Action> turn(new SetWheelsSpeed("Turn", 1, pipeline, base_speed-turn_speed, base_speed+turn_speed));
			pipeline->push(turn);
		}
		else
		{
			std::shared_ptr<Action> turn(new SetWheelsSpeed("Turn", 1, pipeline, base_speed+turn_speed, base_speed-turn_speed));
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



