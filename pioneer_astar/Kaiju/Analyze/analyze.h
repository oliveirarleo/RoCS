//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_ANALYZE_H_
#define ARCH_ANALYZE_H_

#include "../Util/observer.h"
#include "../Util/publisher.h"

template <typename ObservedValue, typename PublishedValue>
class Analyze : public Observer, public Publisher
{
public:
	Analyze();
};


#endif // ARCH_ANALYZE_H_
