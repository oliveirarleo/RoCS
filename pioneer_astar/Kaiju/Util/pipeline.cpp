//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include <Util/pipeline.h>
#include <thread>

void Pipeline::push(Action *action)
{
	while(true)
	{
		if(!ul.owns_lock())
		{
			if(action->getValue() >= top_value)
			{
				actions.clear();
				actions.push_back(action);
				top_value = action->getValue();
			}
			return;
		}
		else
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}

}

Pipeline::Pipeline(): actions{},  mu{}, ul{mu, std::defer_lock}, top_value(0)
{
}

bool Pipeline::next(Action **act)
{
	if (!actions.empty())
	{
		ul.lock();
		*act = actions[0];
		actions.erase(actions.begin());
		if(!actions.empty())
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