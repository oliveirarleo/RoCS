//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_TASK_H_
#define ARCH_TASK_H_

#include <vector>
#include "behavior.h"

class Task
{
private:
    std::vector<Behavior> behaviors;

public:
    virtual std::vector< Behavior > getBehavior() = 0;
};

#endif //ARCH_TASK_H_
