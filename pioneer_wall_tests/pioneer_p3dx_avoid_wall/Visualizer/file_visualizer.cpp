//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include <Execute/action.h>
#include "file_visualizer.h"
#include "../../PioneerP3DX/Knowledge/RobotModels/pioneer_p3dx_model.h"

FileVisualizer::FileVisualizer(RobotModel& robot_): running(true), waiting_time(100), robot(robot_)
{
	std::cout << "Abrindo arquivo" << std::endl;
	my_file.open("pos_and_actions.txt");
	my_file << "X, Y, T, Action" << std::endl;
}

FileVisualizer::~FileVisualizer()
{
	running = false;
	if (thread && thread->joinable())
		thread->join();
	std::cout << "Fechando arquivo" << std::endl;
	my_file.close();
}

void FileVisualizer::startThread()
{
	thread = new std::thread(&FileVisualizer::run, this);
}

void FileVisualizer::run()
{
	while(running && my_file.is_open())
	{

		EulerAngle ea = ((PioneerP3DXModel&) robot).getRobotOrientation();
		Position pos = ((PioneerP3DXModel&) robot).getRobotPosition();
		Action* action = ((PioneerP3DXModel&) robot).getCurrentAction();

		if(ea.isValid() && action != nullptr)
		{
			double x = pos.getX();
			double y = pos.getY();
			double t = ea.getGama();

			my_file << x << ", " << y << ", " << t << ", " << action->getName() << std::endl;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(waiting_time));
	}

}
