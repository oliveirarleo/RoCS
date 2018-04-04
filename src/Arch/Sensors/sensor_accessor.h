//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ROCS_SENSOR_ACCESSOR_H
#define ROCS_SENSOR_ACCESSOR_H


template <class T>
class SensorAccessor
{
public:
    virtual T getData() = 0;
};

#endif // ROCS_SENSOR_ACCESSOR_H
