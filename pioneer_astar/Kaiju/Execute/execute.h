//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_EXECUTE_H_
#define ARCH_EXECUTE_H_

#include <vector>
#include <Util/pipeline.h>
#include <thread>
#include "action.h"
#include "../Plan/behavior.h"

class Execute
{
private:
	bool running;
	Pipeline pipeline;
	std::thread *execute_thread;
public:
	Execute() : running(true), pipeline()
	{
	}

	~Execute()
	{
		running = false;
		if (execute_thread && execute_thread->joinable())
			execute_thread->join();
	}

	void startThread()
	{
		execute_thread = new std::thread(&Execute::run, this);
	}

	void run()
	{
		while (running)
		{
			Action *action;
			if (pipeline.next(&action))
				action->act();
			std::this_thread::sleep_for(std::chrono::milliseconds(15));
		}
	}

	Pipeline &getPipeline()
	{
		return pipeline;
	}
};

#endif //ARCH_EXECUTE_H_
