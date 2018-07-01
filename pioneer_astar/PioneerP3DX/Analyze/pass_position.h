//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIONEER_PASS_POSITION_H_
#define PIONEER_PASS_POSITION_H_

#include <Knowledge/position.h>
#include <Analyze/analyze.h>


class PassPosition : public Analyze<std::vector<Position>, std::vector<Position> >
{
public:
	PassPosition(const RobotModel &robot);

	void publishLoop() override;

};


#endif // PIONEER_PASS_POSITION_H_
