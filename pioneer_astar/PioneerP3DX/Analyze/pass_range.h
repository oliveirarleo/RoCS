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
#include "../Knowledge/Data/range_output.h"

class PassRange : public Analyze<std::vector<RangeOutput>, std::vector<RangeOutput>>
{

public:
	PassRange(const RobotModel &robot);

	std::vector<RangeOutput> process(std::vector<RangeOutput> ov) override;


};


#endif // PIONEER_PASS_SONAR_POSITION_H_
