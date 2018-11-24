//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include <Util/pipeline.h>
#include <thread>
#include <iostream>

void Pipeline::push(Action *action)
{
		if (ul.try_lock_for())
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
	if (ul.try_lock_for() && !actions.empty())
	{
		*act = actions[0];
		if (!actions.empty())
			top_value = actions[0]->getValue();
		else
			top_value = 0;
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
	for (int i = 0; i < actions.size(); ++i)
	{
		std::cout << *(actions[i]) << std::endl;
	}

}