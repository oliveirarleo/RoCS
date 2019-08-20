//
// Created by leleco on 06/07/19.
//

#include "P3DXPositionMonitor.h"


P3DXPositionMonitor::P3DXPositionMonitor(Knowledge &knowledge):Monitor(knowledge)
{
}

P3DXPositionMonitor::P3DXPositionMonitor(Knowledge knowledge_, Sensor<Position> *sensor_)
        :Monitor(knowledge_, sensor_)
{
}

Position P3DXPositionMonitor::interpret(Position raw)
{
//	std::cout << raw << "\n";
    return raw;
}
