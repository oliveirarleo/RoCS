//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include "monitor_publisher.h"

MonitorPublisher::MonitorPublisher()
{

}

MonitorPublisher::MonitorPublisher(std::vector < MonitorObserver > observers_)
{
    observers = observers_;
}