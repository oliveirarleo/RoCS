#include "stackString.h"

CStackString::CStackString(const char* str,int l)
{
    _objectType=STACK_STRING;
    if (l>0)
        _value.assign(str,str+l);
}

CStackString::~CStackString()
{
}

std::string CStackString::getValue()
{
    return(_value);
}

void CStackString::setValue(const char* str,int l)
{
    if (l>0)
        _value.assign(str,str+l);
    else
        _value.clear();
}

CStackObject* CStackString::copyYourself()
{
    CStackString* retVal=new CStackString(_value.c_str(),int(_value.length()));
    return(retVal);
}
