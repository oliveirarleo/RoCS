//
// Created by leleco on 05/12/18.
//

#ifndef PIONEER_ORIENTATION_VREP_MONITOR_H
#define PIONEER_ORIENTATION_VREP_MONITOR_H


#include <Util/orientation.h>
#include <Monitor/monitor.h>

class OrientationVREPMonitor : public Monitor<Orientation, Orientation>
{
public:
	explicit OrientationVREPMonitor(Knowledge &knowledge);

	OrientationVREPMonitor(Knowledge knowledge_, Sensor<Orientation> *orientation_sensor);

	Orientation interpret(Orientation raw) override;
};


#endif //PIONEER_ORIENTATION_VREP_MONITOR_H
