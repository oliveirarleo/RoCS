#include "stackNumber.h"

CStackNumber::CStackNumber(double n)
{
    _objectType=STACK_NUMBER;
    _value=n;
}

CStackNumber::~CStackNumber()
{
}

float CStackNumber::getFloatValue()
{
    return((float)_value);
}

double CStackNumber::getValue()
{
    return(_value);
}

void CStackNumber::setFloatValue(float n)
{
    _value=(double)n;
}

void CStackNumber::setValue(double n)
{
    _value=n;
}

CStackObject* CStackNumber::copyYourself()
{
    CStackNumber* retVal=new CStackNumber(_value);
    return(retVal);
}
