//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIONEER_PASS_VREP_POSITION_H
#define PIONEER_PASS_VREP_POSITION_H


#include <Analyze/analyze.h>

class PassVREPPosition : public Analyze<std::vector<Position>, std::vector<Position>>
{
public:
	explicit PassVREPPosition(Knowledge &knowledge_);

	std::vector<Position> mergeAndProcess(std::vector<Position> ov) override;
};


#endif //PIONEER_PASS_VREP_POSITION_H
