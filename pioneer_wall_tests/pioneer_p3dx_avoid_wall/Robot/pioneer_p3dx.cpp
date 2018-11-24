//
// Created by leonardo on 16/11/18.
//

#include "pioneer_p3dx.h"

PioneerP3DX::PioneerP3DX()
:Robot(), sonars(), wheels(), knowledge(), avoid_wall_model(execute.getPipeline(), sonars, wheels)
{

}


void PioneerP3DX::run()
{

}