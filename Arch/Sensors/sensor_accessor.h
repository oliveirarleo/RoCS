//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ROCS_SENSOR_ACCESSOR_H
#define ROCS_SENSOR_ACCESSOR_H


template <typename DataType>
class SensorAccessor
{

public:
    virtual DataType getData();
};

#endif // ROCS_SENSOR_ACCESSOR_H
