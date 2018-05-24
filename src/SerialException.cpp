// SerialException.cpp: implementation of the CSerialException class.
//
//////////////////////////////////////////////////////////////////////

#include "stdio.h"
#include "SerialException.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSerialException::CSerialException()
{
	_dataSize = 0;
}

CSerialException::~CSerialException()
{

}
CSerialException::CSerialException(const CSerialException& exp)
{
	*this = exp;
}
CSerialException& CSerialException::operator=(const CSerialException& exp)
{
	_dataSize = exp._dataSize;
	_errInfo = exp._errInfo;
	return *this;
}