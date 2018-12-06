//
// Created by leleco on 06/12/18.
//

#include "go_to_origin_action.h"

GoToOriginAction::GoToOriginAction(const std::string &name_, double value_, WheelVREP &left_wheel, WheelVREP &right_wheel, Pipeline &pipeline)
	:Action(name_, value_), left_wheel(left_wheel), right_wheel(right_wheel), pipeline(pipeline)
{
}
