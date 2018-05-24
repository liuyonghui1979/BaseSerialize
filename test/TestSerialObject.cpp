#include "TestSerialObject.h"
#include "SerialOperator.h"


CTestSerialObject::CTestSerialObject(void) : CBaseSerialObject(BASECLASS_ID)
{
}


CTestSerialObject::~CTestSerialObject(void)
{
}

void CTestSerialObject::SerialMember(CSerialOperator& oper)
{
	oper << m_nData;
}
// �������ݲ���
void CTestSerialObject::ParseMember(CSerialOperator& oper)
{
	oper >> m_nData;
}