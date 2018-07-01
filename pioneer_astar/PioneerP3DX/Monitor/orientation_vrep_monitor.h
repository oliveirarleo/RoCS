//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIONEER_ORIENTATION_VREP_MONITOR_H_
#define PIONEER_ORIENTATION_VREP_MONITOR_H_


#include <Monitor/monitor.h>
#include "../Sensors/orientation_sensor.h"

class OrientationVREPMonitor: public Monitor<EulerAngle>
{
public:
	OrientationVREPMonitor(std::vector<OrientationSensor *> &sensors_);

	void publishLoop() override;

};


#endif // PIONEER_ORIENTATION_VREP_MONITOR_H_
