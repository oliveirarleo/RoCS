//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_MONITOR_H_
#define ARCH_MONITOR_H_

#include "interpteter.h"
#include "../Sensors/sensor.h"
#include "monitor_publisher.h"

template <typename DataType, typename SensorOutput>
class Monitor: public Interpreter <DataType, SensorOutput>
{
private:
    Sensor sensor;
    MonitorPublisher monitor_publisher;

public:
    Monitor(Sensor sensor_, MonitorPublisher monitor_publisher_);
    virtual void run() = 0;
};

#endif // ARCH_MONITOR_H_
