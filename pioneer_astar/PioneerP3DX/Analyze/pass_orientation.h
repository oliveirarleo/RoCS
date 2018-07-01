//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIONEER_PASS_ORIENTATION_H_
#define PIONEER_PASS_ORIENTATION_H_


#include <Analyze/analyze.h>
#include "../Knowledge/euler_angle.h"

class PassOrientation: public Analyze<std::vector<EulerAngle>, std::vector<EulerAngle>>

{
public:
	PassOrientation(const RobotModel &robot);

	void publishLoop() override;

};


#endif // PIONEER_PASS_ORIENTATION_H_