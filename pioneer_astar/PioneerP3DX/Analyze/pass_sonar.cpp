//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include <remoteApi/extApiPlatform.h>
#include "pass_sonar.h"

PassSonar::PassSonar(const RobotModel &robot) : Analyze(robot)
{
}

void PassSonar::publishLoop()
{
	while (publishing)
	{
		publish(value);


		using namespace std::chrono_literals;
		std::this_thread::sleep_for(25ms);
	}

}

