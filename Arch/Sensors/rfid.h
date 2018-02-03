//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_RFID_H
#define ARCH_RFID_H

#include "sensor.h"

class RFID: public Sensor
{
private:
    double max_range;

public:
    RFID(double);
};

#endif //ARCH_RFID_H
