//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include <thread>
#include <cmath>
#include "avoid_wall.h"
#include "turn_angle.h"
#include "../../Sensors/orientation_vrep_sensor.h"
#include "../../Knowledge/RobotModels/pioneer_p3dx_model.h"
#include "move_wheels.h"

void AvoidWall::act()
{
	MoveWheels mw1{wheels, 0, 0};
	mw1.act();

	OrientationVREPSensor* os = ((PioneerP3DXModel &)robot).getOrientationSensor();

	EulerAngle first_angle{};
	do
	{
		os->getData(first_angle);
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}while(!first_angle.isValid());

	EulerAngle angle;
	double an;
	double base_angle = first_angle.getGama()+M_PI/3.4;
	do
	{
		os->getData(angle);
		wheels = ((PioneerP3DXModel &)robot).getWheels();
		TurnAngle ta{robot, wheels, angle.getGama(),base_angle};
		ta.act();
		an = base_angle - angle.getGama();
		if(an >= M_PI)
			an = an - 2*M_PI;
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}while (std::abs(an) >0.02);


	MoveWheels mw{wheels, 2, 2};
	mw.act();

	std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

AvoidWall::AvoidWall(double value_, RobotModel &robot,  std::vector<WheelVREP *> &wheels,  std::vector<RangeVREP *> &ranges)
				: Action(value_), robot(robot), wheels(wheels), ranges(ranges)
{
}
