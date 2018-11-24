//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIPELINE_H_
#define PIPELINE_H_

#include <iostream>
#include <thread>
#include <mutex>
#include <deque>
#include <Execute/action.h>

class Pipeline
{
protected:
	std::deque<Action *> actions;
	std::timed_mutex mu;
	std::unique_lock<std::timed_mutex> ul;
	double top_value;

public:
	Pipeline();

	void push(Action *action);

	bool next(Action **action);

	bool isEmpty();

	void printValues();
};


void Pipeline::push(Action *action)
{
	if (ul.try_lock_for(std::chrono::milliseconds(5)))
	{
		actions.push_back(action);
		ul.unlock();
	}
}

Pipeline::Pipeline() : actions{}, mu{}, ul{mu, std::defer_lock}, top_value(0)
{
}

bool Pipeline::next(Action **act)
{
	if (ul.try_lock_for(std::chrono::milliseconds(5)) && !actions.empty())
	{
		*act = actions.front();
		actions.pop_front();
//		if (!actions.empty())
//			top_value = actions[0].getValue();
//		else
//			top_value = 0;
		ul.unlock();
		return true;
	}
	return false;
}

bool Pipeline::isEmpty()
{
	return actions.empty();
}

void Pipeline::printValues()
{
	for (auto &action : actions)
	{
		std::cout << action << std::endl;
	}

}

#endif // PIPELINE_H_

