#include <iostream>
#include "pioneer_p3dx_avoid_wall/Robot/pioneer_p3dx.h"

int main()
{
	std::cout << "Hello, World!" << std::endl;

	PioneerP3DX pioneer_p3dx{};

	pioneer_p3dx.run();

	return 0;
}