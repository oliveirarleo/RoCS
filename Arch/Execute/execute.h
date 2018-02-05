//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_EXECUTE_H_
#define ARCH_EXECUTE_H_

#include <vector>
#include "action.h"
#include "../Plan/behavior.h"

class Execute
{
private:
    std::vector< Action > actions;
    virtual Action mapping(Behavior) = 0;

public:
    virtual void run() = 0;
};

#endif //ARCH_EXECUTE_H_
