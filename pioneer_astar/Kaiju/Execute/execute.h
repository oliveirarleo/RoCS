//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_EXECUTE_H_
#define ARCH_EXECUTE_H_

#include <vector>
#include <thread>

#include <Util/pipeline.h>
#include <Execute/action.h>
#include <Plan/behavior.h>
#include <Knowledge/robot_model.h>

class Execute
{
private:
	RobotModel &robot;
	Pipeline pipeline;
	bool running;
	int waiting_time;
	std::thread *execute_thread;
public:
	Execute(RobotModel &robot_) : robot(robot_), pipeline(), running(true), waiting_time(25)
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
			Action *action = nullptr;
			if (pipeline.next(&action) && action != nullptr)
			{
//					action->act();
				action = nullptr;
			}

			std::this_thread::sleep_for(std::chrono::milliseconds(waiting_time));
		}
	}

	Pipeline &getPipeline()
	{
		return pipeline;
	}
};

#endif //ARCH_EXECUTE_H_