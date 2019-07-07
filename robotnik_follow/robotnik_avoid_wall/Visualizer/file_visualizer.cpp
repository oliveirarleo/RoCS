//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include <Execute/action.h>
#include <Knowledge/knowledge.h>
#include "file_visualizer.h"
#include "../Knowledge/robotnik_knowledge.h"

FileVisualizer::FileVisualizer(Knowledge& knowledge_): running(false), waiting_time(50), thread(nullptr), knowledge(knowledge_)
{
	std::cout << "Abrindo arquivo" << std::endl;
	my_file.open("pos_and_actions.txt");
	my_file << "X, Y, T, Action" << std::endl;
}

FileVisualizer::~FileVisualizer()
{
	running = false;
	std::this_thread::sleep_for(std::chrono::milliseconds(waiting_time));
	if (thread && thread->joinable())
		thread->join();
	std::cout << "Fechando arquivo" << std::endl;
	my_file.close();
}

void FileVisualizer::startThread()
{
	running = true;
	thread = new std::thread(&FileVisualizer::run, this);
}

void FileVisualizer::run()
{
	while(running && my_file.is_open())
	{

		Orientation ea = ((RobotnikKnowledge&) knowledge).getRobotOrientation();
		Position pos = ((RobotnikKnowledge &) knowledge).getRobotPosition();
		std::shared_ptr<Action> action = ((RobotnikKnowledge &) knowledge).getCurrentAction();

		if(ea.isValid() && pos.isValid() && action != nullptr)
		{
			double x = pos.getX();
			double y = pos.getY();
			double t = ea.getGamma();

			my_file << x << ", " << y << ", " << t << ", " << action->getName() << "\n";
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(waiting_time));
	}

}
