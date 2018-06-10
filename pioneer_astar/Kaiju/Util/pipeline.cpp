//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include <Util/pipeline.h>

void Pipeline::push(Action* action)
{
	actions.push_back(action);
}

Action* Pipeline::next()
{
	if(!actions.empty())
	{
		Action* ac = actions.back();
		actions.pop_back();
		return ac;
	}
	return nullptr;

}