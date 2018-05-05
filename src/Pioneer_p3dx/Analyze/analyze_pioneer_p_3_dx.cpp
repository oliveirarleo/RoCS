//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include "analyze_pioneer_p_3_dx.h"
#include "../Monitor/monitor_sonar_vrep.h"

AnalyzePioneerP3DX::AnalyzePioneerP3DX( std::vector<MonitorSonarVrep> &monitors_) : monitors(monitors_)
{

}

//void AnalyzePioneerP3DX::run()
//{
//
//}
//
//void AnalyzePioneerP3DX::update()
//{
//
//}

bool AnalyzePioneerP3DX::getSonarData(int id, Position& position, char** state)
{
	return ((MonitorSonarVrep)monitors[id]).getSonarData(position, state);
}

std::vector<MonitorSonarVrep> &AnalyzePioneerP3DX::getMonitors() const
{
	return monitors;
}
