#include <iostream>
#include "Robot/robotnik.h"

int main()
{
	std::cout << "Hello, World!" << std::endl;

	Robotnik robot{};

	robot.run();

	return 0;
}