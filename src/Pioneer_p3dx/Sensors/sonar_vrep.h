//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_SONAR_VREP_H_
#define ARCH_SONAR_VREP_H_


extern "C" {
#include "../../lib/remoteApi/extApi.h"
}

#include <ostream>
#include <string>
#include "Sensors/sonar.h"
#include "Knowledge/position.h"
#include "Knowledge/robot_model.h"
#include "../Connection/connection.h"

class SonarVREP : public Sonar<Position>
{
private:
	bool is_connected = false;
	int sonar_handle;

	Connection& connection;
	RobotModel& robot;

public:
	SonarVREP(const std::string &name_, Connection &connection_, RobotModel &robot_, double weight_, Position position_,
						double bandwidth_, double max_range_, double resolution_, double fov_angle_, double beam_angle_,
						double scan_interval_);

	SonarVREP(const std::string &name_, Connection &connection_, const RobotModel &robot_);

	SonarVREP(const std::string &name_, const RobotModel &robot_);

	bool sensorIsConnected();

	bool getData(Position &position) override;

	bool getData(Position &position, char& state);

	friend std::ostream &operator<<(std::ostream &os, const SonarVREP &example);

	double getBandwidth() const;

	const Position &getPosition() const;

	double getWeight() const;

	int getSonarHandle() const;

	const std::string &getName() const;

	void setPosition();
};

#endif //ARCH_SONAR_VREP_H_
