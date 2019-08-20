//
// Created by leleco on 06/07/19.
//

#ifndef ROBOTNIK_FOLLOW_P3DXPOSITIONSENSOR_H
#define ROBOTNIK_FOLLOW_P3DXPOSITIONSENSOR_H


#include <Util/position.h>
#include "../Connection/connection.h"
#include "position_vrep_sensor.h"

class P3DXPositionSensor: public Sensor<Position>
    {
    private:
        Connection &connection;
        int handle;

    public:
        explicit P3DXPositionSensor(Connection &connection_);

        void connect(int handle_);

        bool getData(Position &value) override;


};


#endif //ROBOTNIK_FOLLOW_P3DXPOSITIONSENSOR_H
