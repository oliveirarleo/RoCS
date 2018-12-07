//
// Created by leleco on 06/12/18.
//
#include <cmath>

#include "go_to_position.h"
#include "turn_to_angle.h"
#include "set_wheels_speed.h"

GoToPosition::GoToPosition(const std::string &name_, double value_, Pipeline *pipeline_,
                           Position position_, Orientation orientation_, Position destination)
	:Action(name_, value_, pipeline_), left_wheel(nullptr), right_wheel(nullptr), position(position_),
	 orientation(orientation_), origin(destination), angle_threshold(0.1), distance_threshold(0.1)
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

//		std::cout << position << "\n";
//		std::cout << res << " dist from origin " << res.abs() << "\n";
//		std::cout << angle_difference << "\n";

		if (res.abs() < distance_threshold)
		{
			std::cout << "stop\n";
			std::shared_ptr<Action> stop(new SetWheelsSpeed("Stop", 1, pipeline, 0, 0));
			pipeline->push(stop);
		}
		else if (angle_difference > angle_threshold)
		{
			std::cout << "turning clock " << angle_difference << " \n";
			std::shared_ptr<Action> turn_to_angle(new TurnToAngle("TurnToAngle", 1, pipeline, orientation, gamma, true));
			pipeline->push(turn_to_angle);
		}
		else if (angle_difference < -angle_threshold)
		{
//			std::cout << "turning anticlock " <<angle_difference <<" \n";
			std::shared_ptr<Action> turn_to_angle(new TurnToAngle("TurnToAngle", 1, pipeline, orientation, gamma, false));
			pipeline->push(turn_to_angle);
		}
		else
		{
			std::cout << "go ahead\n";
			std::shared_ptr<Action> go_ahead(new SetWheelsSpeed("GoAhead", 1, pipeline, 1, 1));
			pipeline->push(go_ahead);
		}
	}
	else
	{
		std::cout << "Pipeline null\n";
	}

}