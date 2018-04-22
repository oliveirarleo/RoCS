//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_ANALYZE_OBSERVER_H_
#define ARCH_ANALYZE_OBSERVER_H_

#include "../Util/observer.h"

class AnalyzeObserver : Observer
{
public:
	virtual void update() = 0;
};


#endif // ARCH_ANALYZE_OBSERVER_H_
