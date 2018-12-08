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
	std::deque<std::shared_ptr<Action> > actions;
	std::mutex mu;
//	std::unique_lock<std::mutex> ul;
	double top_value;

public:
	Pipeline()
		:actions{}, mu{}, top_value(0)
	{
	}

	void push(const std::shared_ptr<Action> &action)
	{
		std::lock_guard<std::mutex> lg(mu);
//			std::cout << "Pushing " << *action << "\n";
		if (action->getValue() == top_value)
			actions.push_back(action);
		else if (action->getValue() > top_value)
		{
			actions.clear();
			actions.push_back(action);
		}
	}

	bool next(std::shared_ptr<Action> *action)
	{
		std::lock_guard<std::mutex> lg(mu);
		if (!actions.empty())
		{
			*action = actions.front();
			actions.pop_front();
			if (!actions.empty())
				top_value = actions[0]->getValue();
			else
				top_value = 0;
			return true;
		}
		return false;
	}


	bool isEmpty()
	{
		return actions.empty();
	}


	void printValues()
	{
		for (auto &action : actions)
		{
			std::cout << *action << std::endl;
		}

	}
};

#endif // PIPELINE_H_

