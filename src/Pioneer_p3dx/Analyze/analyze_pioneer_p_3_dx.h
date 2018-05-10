//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIONEER_ANALYZE_PIONEER_P_3_DX_H_
#define PIONEER_ANALYZE_PIONEER_P_3_DX_H_


#include <vector>

#include "Analyze/analyze.h"
#include "Knowledge/position.h"

#include "../Monitor/monitor_sonar_vrep.h"

class AnalyzePioneerP3DX: public Analyze
{
private:
	std::vector<MonitorSonarVrep> &monitors;
public:
	explicit AnalyzePioneerP3DX(std::vector<MonitorSonarVrep> &monitors_);

//	void run() override;

//	void update() override;

	bool getSonarData(int id, Position& position, char& state);

	std::vector<MonitorSonarVrep> &getMonitors() const;
};


#endif // PIONEER_ANALYZE_PIONEER_P_3_DX_H_
