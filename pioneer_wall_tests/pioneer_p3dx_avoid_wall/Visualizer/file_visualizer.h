//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIONEER_FILE_VISUALIZER_H_
#define PIONEER_FILE_VISUALIZER_H_

#include <iostream>
#include <fstream>
#include <thread>
#include <Knowledge/robot_model.h>

class FileVisualizer
{
private:
	std::ofstream my_file;

	bool running;
	int waiting_time;
	std::thread *thread;

	RobotModel& robot;


public:
	FileVisualizer(RobotModel& robot_);

	virtual ~FileVisualizer();

	void startThread();

	void run();

};


#endif // PIONEER_FILE_VISUALIZER_H_
