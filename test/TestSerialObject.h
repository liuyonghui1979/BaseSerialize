#ifndef _TESTSERIALOBJECT_H
#define _TESTSERIALOBJECT_H
#include "baseserialobject.h"
class CTestSerialObject : public CBaseSerialObject
{
public:
	CTestSerialObject(void);
	~CTestSerialObject(void);
	int m_nData;
protected:
	// ���л����ݲ���
	virtual void SerialMember(CSerialOperator& oper);
	// �������ݲ���
	virtual void ParseMember(CSerialOperator& oper);	
public:
	static const unsigned short BASECLASS_ID = 0x01;	
};

#endif