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
	std::unique_lock<std::mutex> ul;
	double top_value;

public:
	Pipeline()
		:actions{}, mu{}, ul{mu, std::defer_lock}, top_value(0)
	{
	}

	void push(std::shared_ptr<Action> action)
	{
		if (ul.try_lock())
		{
//			std::cout << "Pushing " << *action << "\n";
			actions.push_back(action);
			ul.unlock();
		}
	}

	bool next(std::shared_ptr<Action> *action)
	{
		if (ul.try_lock())
		{
			if (!actions.empty())
			{
				*action = actions.front();
				actions.pop_front();
//						if (!actions.empty())
//							top_value = actions[0].getValue();
//						else
//							top_value = 0;
				ul.unlock();
				return true;
			}
			ul.unlock();
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

