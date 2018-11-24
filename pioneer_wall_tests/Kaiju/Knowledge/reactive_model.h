//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIONEER_REACTIVE_MODEL_H_
#define PIONEER_REACTIVE_MODEL_H_

#include <thread>
#include <Util/pipeline.h>

class ReactiveModel
{
protected:
	Pipeline &pipeline;
	bool running;
	std::thread *reactive_model_thread;

public:
	ReactiveModel(Pipeline &pipeline) : pipeline(pipeline), running(false)
	{
	}

	~ReactiveModel()
	{
		running = false;
		if (reactive_model_thread && reactive_model_thread->joinable())
			reactive_model_thread->join();

	}

	virtual void run() = 0;

	void startThread()
	{
		running = true;
		reactive_model_thread = new std::thread(&ReactiveModel::run, this);
	}

};

#endif //PIONEER_REACTIVE_MODEL_H_
