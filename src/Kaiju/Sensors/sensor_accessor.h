//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ROCS_SENSOR_ACCESSOR_H_
#define ROCS_SENSOR_ACCESSOR_H_

template<class T>
class SensorAccessor
{
public:
	virtual bool getData(T &) = 0;
};

#endif // ROCS_SENSOR_ACCESSOR_H_
