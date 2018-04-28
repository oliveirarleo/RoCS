//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_SONAR_VREP_H_
#define ARCH_SONAR_VREP_H_


extern "C" {
#include "extApi.h"
}

#include <ostream>
#include <string>
#include "Sensors/sonar.h"
#include "Knowledge/position.h"
#include "Robot/robot.h"
#include "../Connection/connection.h"

class SonarVREP : public Sonar<Position>
{
private:
	bool is_connected = false;
	int sonar_handle;

	std::string name;
	Connection connection;
	Robot *robot;

public:
	SonarVREP(std::string name_, Connection &connection_, Robot *robot_, double weight_, Position position_,
						double bandwidth_, double max_range_, double resolution_, double fov_angle_, double beam_angle_,
						double scan_interval_);

	bool sensorIsConnected();

	bool getData(Position &position) override;

	friend std::ostream &operator<<(std::ostream &os, const SonarVREP &example);

	double getBandwidth() const;

	const Position &getPosition() const;

	double getWeight() const;

	int getSonar_handle() const;

	const std::string &getName() const;

	void setPosition();
};

#endif //ARCH_SONAR_VREP_H_
