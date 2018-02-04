//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

//#include "ConcreteClasses/Sensors/sensor.h"
#include <iostream>

#include "Util/position.h"
#include "./ConcreteClasses/Sensors/sonar_example.h"

int main(int argc, char* argv[])
{
    using std::cout;
    using std::endl;

    Position pos{33, 44, 55};
    SonarExample sonar{1, pos, 2, 3, 4, 5, 6, 7};


    cout << "hi" << endl;
}