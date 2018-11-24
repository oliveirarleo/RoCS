//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_PLANNER_H_
#define ARCH_PLANNER_H_

#include <thread>
#include <Knowledge/robot_model.h>
#include <Util/observer.h>
#include <Analyze/analyze.h>
#include <Util/pipeline.h>

class Planner
{
protected:
	Knowledge &knowledge;
	Pipeline &pipeline;

	bool running;
	std::thread *planner_thread;


public:
	Planner(Knowledge &knowledge, Pipeline &pipeline) : knowledge(knowledge), pipeline(pipeline), running(true)
	{

	}

	~Planner()
	{
		running = false;
		if (planner_thread && planner_thread->joinable())
			planner_thread->join();
	}

	void startThread()
	{
		planner_thread = new std::thread(&Planner::run, this);
	}

	virtual void run() = 0;
};


#endif //ARCH_PLANNER_H_
