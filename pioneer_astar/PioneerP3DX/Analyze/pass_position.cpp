//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include "pass_position.h"

PassPosition::PassPosition(const RobotModel &robot) : Analyze(robot)
{
}

void PassPosition::publishLoop()
{
	while (publishing)
	{
		publish(value);

		using namespace std::chrono_literals;
		std::this_thread::sleep_for(25ms);
	}

}
