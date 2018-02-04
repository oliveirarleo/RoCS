//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_INTERPTETER_H_
#define ARCH_INTERPTETER_H_

template <typename DataTypeIn, typename DataTypeOut>
class Interpreter
{
public:
    virtual DataTypeOut interpret(DataTypeIn) = 0;

};

#endif //ARCH_INTERPTETER_H_
