//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

extern "C" {
#include "extApi.h"
}

#include <iostream>
#include "sonar_vrep.h"
#include "../Robot/pioneer_p_3_dx.h"


SonarVREP::SonarVREP(std::string name_, Connection &connection_, Robot *robot_, double weight_, Position position_,
										 double bandwidth_, double max_range_, double resolution_, double fov_angle_, double beam_angle_,
										 double scan_interval_)
	: Sonar(weight_, position_, bandwidth_, max_range_, resolution_, fov_angle_, beam_angle_, scan_interval_),
		name(name_), connection(connection_), robot(robot_)
{
	this->name.assign(name_);

	if (simxGetObjectHandle(connection.getClientId(), (const simxChar *) name.c_str(), (simxInt *) &sonar_handle,
													(simxInt) simx_opmode_oneshot_wait) == simx_return_ok)
	{
		is_connected = true;
		std::cout << "Connected to sensor " << name << std::endl;
	}
	else
	{
		std::cout << "Not connected to sensor " << name << std::endl;
	}

}

bool SonarVREP::sensorIsConnected()
{
	return is_connected;
}

bool SonarVREP::getData(Position &position)
{
	bool detected = false;
	float point[3];
	simxReadProximitySensor(connection.getClientId(), sonar_handle, (simxUChar *) &detected, point, nullptr, nullptr,
													simx_opmode_streaming);
	if (detected)
	{
		position.setPosition((double) point[0], (double) point[1], (double) point[2]);
		return true;
	}
	return false;
}

int SonarVREP::getSonar_handle() const
{
	return sonar_handle;
}

const std::string &SonarVREP::getName() const
{
	return name;
}

double SonarVREP::getWeight() const
{
	return weight;
}

const Position &SonarVREP::getPosition() const
{
	return position;
}

double SonarVREP::getBandwidth() const
{
	return bandwidth;
}

std::ostream &operator<<(std::ostream &os, const SonarVREP &example)
{
	os << static_cast<const Sonar<Position> &>(example);
	return os;
}

void SonarVREP::setPosition()
{
	if (is_connected)
	{
		float pos[3];
		simxGetObjectPosition(connection.getClientId(), sonar_handle, ((Pioneer_p3dx *) robot)->getHandle(), pos,
													simx_opmode_streaming);
		position.setPosition((double) pos[0], (double) pos[1], (double) pos[2]);
	}
}


