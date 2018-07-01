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
#include "../Knowledge/Data/sonar_output.h"

class PassSonar : public Analyze<std::vector<SonarOutput>, std::vector<SonarOutput>>
{

public:
	PassSonar(const RobotModel &robot);

	void publishLoop() override;

};


#endif // PIONEER_PASS_SONAR_POSITION_H_
