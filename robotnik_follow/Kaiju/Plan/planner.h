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
	Pipeline *pipeline;

	bool running;
	int waiting_time;
	std::thread *planner_thread;


public:
	Planner(Knowledge &knowledge)
		:knowledge(knowledge), pipeline(nullptr), running(true), waiting_time(50), planner_thread(nullptr)
	{

	}

	Planner(Knowledge &knowledge, Pipeline *pipeline)
		:knowledge(knowledge), pipeline(pipeline), running(true), waiting_time(50), planner_thread(nullptr)
	{

	}

	void setPipeline(Pipeline *pipeline)
	{
		Planner::pipeline = pipeline;
	}

	~Planner()
	{
		running = false;
		std::this_thread::sleep_for(std::chrono::milliseconds(waiting_time));
		if (planner_thread && planner_thread->joinable())
			planner_thread->join();
	}

	void startThread()
	{
		planner_thread = new std::thread(&Planner::run, this);
	}

	virtual void planIteration() = 0;

	void run()
	{
		while (running)
		{
			planIteration();
			std::this_thread::sleep_for(std::chrono::milliseconds(waiting_time));
		}
	}
};


#endif //ARCH_PLANNER_H_
