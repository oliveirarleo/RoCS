//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIONEER_REACTIVE_MODEL_H_
#define PIONEER_REACTIVE_MODEL_H_

#include <thread>
#include <Util/pipeline.h>
#include <Util/observer.h>

template<typename ObservedValue>
class ReactiveModel : public Observer<ObservedValue>
{
protected:
	Pipeline *pipeline;
	bool running;
	int waiting_time;
	std::thread *reactive_model_thread;

public:
	ReactiveModel() : pipeline(nullptr), running(false), waiting_time(50), reactive_model_thread(nullptr)
	{
	}

	explicit ReactiveModel(Pipeline *pipeline) : pipeline(pipeline), running(false), waiting_time(50), reactive_model_thread(nullptr)
	{
	}

	~ReactiveModel()
	{
		running = false;
		std::this_thread::sleep_for(std::chrono::milliseconds(5));
		if (reactive_model_thread && reactive_model_thread->joinable())
			reactive_model_thread->join();
	}

	virtual void react() = 0;

	void run()
	{
		while (running)
		{
			react();
			std::this_thread::sleep_for(std::chrono::milliseconds(waiting_time));
		}
	}

	void startThread()
	{
		running = true;
		reactive_model_thread = new std::thread(&ReactiveModel::run, this);
	}

	void setPipeline(Pipeline *pipeline)
	{
		ReactiveModel::pipeline = pipeline;
	}

};

#endif //PIONEER_REACTIVE_MODEL_H_
