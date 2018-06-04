//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include "a_star_pioneer.h"
#include "../Knowledge/pioneer_p3dx_model.h"
#include "../Monitor/sonar_vrep_monitor.h"

AStarPioneer::AStarPioneer()
{
	PioneerP3DXModel p3dx_model{};
	std::vector<SonarVREP> sonars = p3dx_model.getSonars();
	std::vector<SonarVREPMonitor*> sonar_monitors;

	for (int i = 0; i < 16; ++i)
	{
		sonar_monitors.push_back(new SonarVREPMonitor{(Sensor<Position>&)sonars[i]});
	}

	while (true)
	{
		std::cout << "de 1 em 1" << std::endl;
		using namespace std::chrono_literals;
		std::this_thread::sleep_for(1s);
	}


}
