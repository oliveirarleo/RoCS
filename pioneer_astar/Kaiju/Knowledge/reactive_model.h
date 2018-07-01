//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIONEER_REACTIVE_MODEL_H_
#define PIONEER_REACTIVE_MODEL_H_

#include <thread>
#include <Util/pipeline.h>
#include "robot_model.h"

class ReactiveModel
{
public:
	bool running;
	std::thread *reactive_model_thread;

	RobotModel &robot;
	Pipeline &pipeline;

	ReactiveModel(RobotModel &robot, Pipeline &pipeline) : robot(robot), pipeline(pipeline), running(true),
																												 reactive_model_thread(nullptr)
	{
	}

	~ReactiveModel()
	{
		running = false;
		if (reactive_model_thread && reactive_model_thread->joinable())
			reactive_model_thread->join();
	}

	void startThread()
	{
		reactive_model_thread = new std::thread(&ReactiveModel::run, this);
	}

	virtual void run() = 0;
};

#endif //PIONEER_REACTIVE_MODEL_H_
