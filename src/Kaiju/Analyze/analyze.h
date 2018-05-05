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
#include "monitor_observer.h"
#include "Monitor/monitor.h"

class Analyze : public MonitorObserver
{
protected:
//	std::vector<Processor> processors;
//	std::vector<Merger> mergers;
//	AnalyzePublisher publisher;

public:
//	Analyze(const std::vector<Processor> &processors, const std::vector<Merger> &mergers)
//		: processors(processors),
//			mergers(mergers)
//			publisher(publisher)
//	{
//	}
	Analyze()
	{
	}

//	virtual void run() = 0;

};


#endif // ARCH_ANALYZE_H_
