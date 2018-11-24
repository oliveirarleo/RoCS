//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIONEER_SONAR_VREP_MONITOR_H_
#define PIONEER_SONAR_VREP_MONITOR_H_

#include <Monitor/monitor.h>
#include <thread>
#include "../Knowledge/Data/range_output.h"
#include "../Sensors/range_vrep_sensor.h"

class RangeVREPMonitor : public Monitor<RangeOutput, RangeOutput>
{
public:
	RangeVREPMonitor(std::vector<RangeVREPSensor *> &sensors_);

	void publishLoop() override;

    RangeOutput interpret(RangeOutput raw) override;

};


#endif // PIONEER_SONAR_VREP_MONITOR_H_

