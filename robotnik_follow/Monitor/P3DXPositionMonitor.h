//
// Created by leleco on 06/07/19.
//

#ifndef ROBOTNIK_FOLLOW_P3DXPOSITIONMONITOR_H
#define ROBOTNIK_FOLLOW_P3DXPOSITIONMONITOR_H


#include <Util/position.h>
#include <Knowledge/knowledge.h>
#include <Sensors/sensor.h>
#include <Monitor/monitor.h>

class P3DXPositionMonitor : public Monitor<Position, Position>
{
public:
    explicit P3DXPositionMonitor(Knowledge &knowledge);

    P3DXPositionMonitor(Knowledge knowledge_, Sensor<Position> *sensor_);

    Position interpret(Position raw) override;
};

#endif //ROBOTNIK_FOLLOW_P3DXPOSITIONMONITOR_H
