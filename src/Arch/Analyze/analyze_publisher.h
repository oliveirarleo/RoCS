//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_ANALYZE_PUBLISHER_H_
#define ARCH_ANALYZE_PUBLISHER_H_

#include "../Util/publisher.h"

class AnalyzePublisher: Publisher
{
    virtual void attach() = 0;
};


#endif // ARCH_ANALYZE_PUBLISHER_H_
