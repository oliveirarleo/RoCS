//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_PROCESSOR_H_
#define ARCH_PROCESSOR_H_

template <typename DataType, typename... Args>
class Processor {
public:
    virtual void process(DataType) = 0;
};


#endif // ARCH_PROCESSOR_H_
