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
#include <Knowledge/knowledge.h>

class FileVisualizer
{
private:
	std::ofstream my_file;

	bool running;
	int waiting_time;
	std::thread *thread;

	Knowledge& knowledge;


public:
	explicit FileVisualizer(Knowledge& knowledge_);

	~FileVisualizer();

	void startThread();

private:
	void run();

};


#endif // PIONEER_FILE_VISUALIZER_H_
