//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include <remoteApi/extApiPlatform.h>
#include "pass_range.h"

PassRange::PassRange(const RobotModel &robot) : Analyze(robot)
{
}

void PassRange::publishLoop()
{
	while (publishing)
	{
		publish(value);


		using namespace std::chrono_literals;
		std::this_thread::sleep_for(25ms);
	}

}

