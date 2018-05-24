#include "DataInfoSerialItf.h"
#include "SerialOperator.h"
#include <string.h>


CDataInfoSerialItf::CDataInfoSerialItf(void)
{
	_value = 0; 
}


CDataInfoSerialItf::~CDataInfoSerialItf(void)
{
}

// –Ú¡–ªØ
void CDataInfoSerialItf::SerialData(CSerialOperator& oper)
{
	oper << _value << _string;
}
// Ω‚Œˆ
void CDataInfoSerialItf::ParseData(CSerialOperator& oper)
{
	oper >> _value >> _string;
}

CDataInfoSerialItf::CDataInfoSerialItf(const CDataInfoSerialItf& data)
{
	_value = data._value;
	_string = data._string;
}
CDataInfoSerialItf& CDataInfoSerialItf::operator=(const CDataInfoSerialItf& data)
{
	_value = data._value;
	_string = data._string;
	return *this;
}