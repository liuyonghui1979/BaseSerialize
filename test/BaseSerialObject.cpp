// SerialObject.cpp: implementation of the CSerialObject class.
//
//////////////////////////////////////////////////////////////////////

#include "BaseSerialObject.h"
#include "SerialException.h"
#include "SerialOperator.h"
#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBaseSerialObject::CBaseSerialObject(unsigned short nID) : CRPCBaseObject(nID)
{

}

CBaseSerialObject::~CBaseSerialObject()
{

}



// ���л�
void CBaseSerialObject::SerialData(CSerialOperator& oper)
{
	unsigned int nDataLen = 0;
	unsigned int nBgn = oper.GetDataEnd();
	// д�볤��
	oper << nDataLen;	
	unsigned short classID = _classID;
	oper << classID;
	oper << _version;
	SerialMember(oper);
	// дͷ
	unsigned int nEnd = oper.GetDataEnd();
	oper.SetDataEnd(nBgn);
	nDataLen = nEnd - nBgn - 4;
	oper << nDataLen;
	oper.SetDataEnd(nEnd);
}

// ����
void CBaseSerialObject::ParseData(CSerialOperator& oper)
{
	unsigned int nDataLen = 0;
	unsigned short classID = 0;
	oper >> nDataLen;
	if(nDataLen > oper.GetDataLen())
	{
		CSerialException excep;
		excep._dataSize = nDataLen;
		excep._errInfo = CSerialException::ERROR_READ_DATALEN;
		throw excep;
	}
	oper >> classID;
	if(classID != _classID)
	{
		CSerialException excep;
		excep._dataSize = 0;
		excep._errInfo = CSerialException::ERROR_READ_DATAINFO;
		throw excep;
	}	
	oper >> _version;
	// ��������
	ParseMember(oper);	
}


