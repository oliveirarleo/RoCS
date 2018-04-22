//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_ANALYZE_H_
#define ARCH_ANALYZE_H_

#include <vector>
#include "merger.h"
#include "processor.h"
#include "analyze_publisher.h"
#include "../Plan/analyze_observer.h"

class Analyze
{
private:
	std::vector<Processor> processors;
	std::vector<Merger> mergers;
	std::vector<Observer> observers;
	AnalyzePublisher publisher;

public:
	Analyze::Analyze(const std::vector<Processor> &processors, const std::vector<Merger> &mergers,
					 const std::vector<Observer> &observers, AnalyzePublisher &publisher) :
			processors(processors),
			mergers(mergers),
			observers(observers),
			publisher(publisher)
	{
	}

	virtual void run() = 0;

};


#endif // ARCH_ANALYZE_H_
