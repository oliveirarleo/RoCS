//
// Created by leleco on 06/07/19.
//

#ifndef ROBOTNIK_FOLLOW_PASSP3DXPOSITION_H
#define ROBOTNIK_FOLLOW_PASSP3DXPOSITION_H


#include <Analyze/analyze.h>

class PassRobotnikPosition : public Analyze<std::vector<Position>, std::vector<Position>>
{
public:
    explicit PassRobotnikPosition(Knowledge &knowledge_);

    std::vector<Position> mergeAndProcess(std::vector<Position> ov) override;
};


#endif //ROBOTNIK_FOLLOW_PASSP3DXPOSITION_H
