#include "stackNull.h"

CStackNull::CStackNull()
{
    _objectType=STACK_NULL;
}

CStackNull::~CStackNull()
{
}

CStackObject* CStackNull::copyYourself()
{
    CStackNull* retVal=new CStackNull();
    return(retVal);
}
