//
// Created by leleco on 05/12/18.
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
