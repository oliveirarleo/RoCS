//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_MERGER_H_
#define ARCH_MERGER_H_


template <typename DataTypeIn, typename DataTypeOut, typename... Args>
class Merger {
public:
    virtual DataTypeOut merge(DataTypeIn, Args...) = 0;

};


#endif // ARCH_MERGER_H_
