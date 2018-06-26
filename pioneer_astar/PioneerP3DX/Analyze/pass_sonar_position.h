//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIONEER_PASS_SONAR_POSITION_H_
#define PIONEER_PASS_SONAR_POSITION_H_


#include <Analyze/analyze.h>
#include <thread>
#include <Knowledge/robot_model.h>
#include "../Sensors/sonar_output.h"

class PassSonarPosition : public Analyze<std::vector<SonarOutput>, std::vector<SonarOutput>>
{

public:
	PassSonarPosition(const RobotModel &robot);

	void publishLoop() override;

};


#endif // PIONEER_PASS_SONAR_POSITION_H_
