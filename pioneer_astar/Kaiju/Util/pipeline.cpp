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

bool Pipeline::next(Action** act)
{
	if(!actions.empty())
	{
		*act = actions.back();
		actions.pop_back();
		return true;
	}
	return false;

}

bool Pipeline::isEmpty(){
	return actions.empty();
}