//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include <cmath>

#include "go_to_position.h"
#include "turn_to_angle.h"
#include "set_wheels_speed.h"

GoToPosition::GoToPosition(const std::string &name_, double value_, Pipeline *pipeline_,
                           Position position_, Orientation orientation_, Position destination)
	:Action(name_, value_, pipeline_), left_wheel(nullptr), right_wheel(nullptr), position(position_),
	 orientation(orientation_), origin(destination), angle_threshold(0.1), distance_threshold(0.2)
{

}

void GoToPosition::setActuators(std::vector<std::vector<Actuator *> > &actuators)
{
	Action::actuators = actuators;
	left_wheel = (WheelVREP *) (actuators[0][0]);
	right_wheel = (WheelVREP *) (actuators[0][1]);
}

void GoToPosition::act()
{
	if (pipeline)
	{
		double base_speed = 1.5;
		Position res = origin - position;
		double gamma = res.arg();

		double angle_difference = gamma - orientation.getGamma();
		if (angle_difference <= -M_PI)
		{
			angle_difference += 2 * M_PI;
		}
		else if (angle_difference > M_PI)
		{
			angle_difference -= 2 * M_PI;
		}

//		std::cout << res.abs() << "\n";
//		std::cout << origin << "\n";
//		std::cout << position << "\n";
//		std::cout << res << " dist from origin " << res.abs() << "\n";
//		std::cout << angle_difference << "\n";

		if (res.abs() < distance_threshold)
		{
//			std::cout << "stop\n";
			std::shared_ptr<Action> stop(new SetWheelsSpeed("Stop", 1, pipeline, 0, 0));
			pipeline->push(stop);
		}
		else if ((angle_difference > angle_threshold*2) or (angle_difference < -angle_threshold*2))
		{
//			std::cout << "turning clock " << angle_difference << " \n";
			std::shared_ptr<Action> turn_to_angle(new TurnToAngle("TurnToAngle", 1, pipeline, orientation, gamma, 0, base_speed));
			pipeline->push(turn_to_angle);
		}
		else if ((angle_difference > angle_threshold) or (angle_difference < -angle_threshold))
		{
//			std::cout << "turning clock " << angle_difference << " \n";
			std::shared_ptr<Action> turn_to_angle(new TurnToAngle("TurnToAngle", 1, pipeline, orientation, gamma, base_speed, base_speed));
			pipeline->push(turn_to_angle);
		}
		else
		{
//			std::cout << "go ahead\n";
			std::shared_ptr<Action> go_ahead(new SetWheelsSpeed("GoAhead", 1, pipeline, base_speed, base_speed));
			pipeline->push(go_ahead);
		}
	}
	else
	{
		std::cout << "Pipeline null\n";
	}

}