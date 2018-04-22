#include "stackBool.h"

CStackBool::CStackBool(bool theValue)
{
    _objectType=STACK_BOOL;
    _value=theValue;
}

CStackBool::~CStackBool()
{
}

bool CStackBool::getValue()
{
    return(_value);
}

void CStackBool::setValue(bool theValue)
{
    _value=theValue;
}

CStackObject* CStackBool::copyYourself()
{
    CStackBool* retVal=new CStackBool(_value);
    return(retVal);
}
