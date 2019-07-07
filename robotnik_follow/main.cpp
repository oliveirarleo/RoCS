#include <iostream>
#include "robotnik_avoid_wall/Robot/robotnik.h"

int main()
{
	std::cout << "Hello, World!" << std::endl;

	Robotnik robot{};

	robot.run();

	return 0;
}